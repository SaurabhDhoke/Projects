"""---------------------------------------------------------------------
Programmer Name : Dhoke Saurabh Vilas 
Script Usage    : This script is used to wish freinds by mail on there b day and names of b day boys are written in log file and send this log file to owner by using mail
Date            : 14.03.2022
---------------------------------------------------------------------"""

import time
from datetime import date
import pandas as pd

import os
import psutil
import time

from sys import *
import schedule

from urllib.request import urlopen
import smtplib
from email import encoders
from email.mime.text import MIMEText
from email.mime.base import MIMEBase
from email.mime.multipart import MIMEMultipart

"""----------------------------------------------------------------"""
def is_connected():
	try:
		urlopen('https://www.google.com/')
		return True
	except:
		return False

"""----------------------------------------------------------------"""
def Mail(bday_boy_mid,BODY,bb_name,FD):	
	connected = is_connected()
	
	if connected :
		MailSender(bday_boy_mid,BODY,bb_name,FD)
	else:
		print("There is no internet Connection...connect Wifi to PC and then Run the script")	
	
	print()	

"""----------------------------------------------------------------"""
def MailSender(bday_boy_mid,BODY,bb_name,FD):
	
	try:
		from_address = "thisissaurabhdhoke@gmail.com"
		to_address = bday_boy_mid
		
		msg = MIMEMultipart()
		msg['From'] = from_address
		msg['To'] = to_address

		body = BODY
		
		Subject = """B-Day Wishes"""
		
		msg['Subject'] = Subject
		msg.attach(MIMEText(body,'plain'))
		
		s = smtplib.SMTP('smtp.gmail.com',587)
		s.starttls()
		s.login(from_address,"30883088")
		
		text = msg.as_string()
		s.sendmail(from_address,to_address,text)
		s.quit()
		FD.write(bb_name + "\t"+ bday_boy_mid + "\n")

	except Exception as E:
		print("Unable to send mail",E)

"""----------------------------------------------------------------"""
def MailSender_Owner(filename):
	fd = open("Owner.txt",'r')
	BODY = fd.read()
	fd.close()
				
	try:
		from_address = "thisissaurabhdhoke@gmail.com"
		to_address = "saurabhdhoke70@gmail.com"
		
		msg = MIMEMultipart()
		msg['From'] = from_address
		msg['To'] = to_address

		body = BODY 

		Subject = """
		Report to Owner about to whome script wishes today... 
		"""
		
		msg['Subject'] = Subject
		msg.attach(MIMEText(body,'plain'))
		
		
		attachment = open(filename,"rb")
		
		p = MIMEBase('application','octet-stream')
		p.set_payload((attachment).read())
		
		encoders.encode_base64(p)
		p.add_header('Content-Disposition',"attachment;filename =  %s"%filename)
		msg.attach(p)
			
		s = smtplib.SMTP('smtp.gmail.com',587)
		s.starttls()
		s.login(from_address,"30883088")
		
		text = msg.as_string()
		s.sendmail(from_address,to_address,text)
		s.quit()

	except Exception as E:
		print("Unable to send mail",E)

"""----------------------------------------------------------------"""
def Compare_dates():
	startTime = time.time()
	
	t = time.localtime()
	current_date = time.strftime("%d/%m",t) 

	File = pd.read_csv('Bday_information.csv')

	list_name    = File.Name
	list_mail_id = File.Mail_id
	list_b_date  = File.B_Date
	list_programmer = File.Programmer

	bday_boy_mid = 0
	it_non_it = "Yes"

	folder_name = "Sended_Wishes"
	if not os.path.exists(folder_name):
		try:
			os.mkdir(folder_name)
		except:
			pass
	
	today = date.today()
	log_path = os.path.join(folder_name,"Wish_on %s.txt"%(today))
	
	separator = "-" * 84
	
	FD = open(log_path,'w')
	FD.write(separator + "\n")
	FD.write("\nLog file created at : "+time.ctime() + "\n\n")
	
	FD.write(separator + "\n")
	FD.write("\nBelow mentioned boys and girls are born on todays date  \n\n")
	FD.write(separator + "\n")

	cnt = 0
	for i in range(0,len(list_b_date),1):
		if current_date == list_b_date[i]:
			bday_boy_mid = list_mail_id[i]
			it_non_it = list_programmer[i]
			bb_name = list_name[i]
			cnt = cnt +1
			
			if it_non_it == "Yes":
				fd = open("Bday_wish_programmer.txt",'r')
				BODY = fd.read()
				fd.close()
				Mail(bday_boy_mid,BODY,bb_name,FD)
				
			else:
				fd = open("Bday_wish_non_Programmer.txt",'r')	
				BODY = fd.read()
				fd.close()
				Mail(bday_boy_mid,BODY,bb_name,FD)
	
	if(cnt == 0):
		FD.write("Today there is No B-day Boy"+ "\n")
	
	endTime = time.time()		
	FD.write(separator + "\n")
	FD.write('Took %s seconds to Run this script.' %(endTime - startTime) + "\n")
	
	FD.write(separator + "\n")
	FD.close()
	
	MailSender_Owner(log_path)	# call to mail sender to owner function
			
"""----------------------------------------------------------------"""					
def main():
	print("\n-------------- Shiv Shambho : Bday Wisher Script ------------------")
	print("Application Name : "+argv[0])
	
	if (len(argv) == 2):
		if ((argv[1] == "-h") or (argv[1] == "-H")):	
			print("This script is used to wish to freind on her bday automatically and write name of friend into log file")
			exit()
			
		if ((argv[1] == "-u") or (argv[1] == "-U")):	
			print("Usage : Application_Name")
			exit()

	while(1):
		try:
			startTime = time.time()
			Compare_dates()
			endTime = time.time()		
			print('Took %s seconds to Run this script.' %(endTime - startTime))
			print("Todays Work is done...\nWe Will meet again tomorrow...")
			time.sleep(86400)
		
		except ValueError:
			print("Error : Invalid datatype of input")
		except Exception as E:
			print("Error : Invalid input",E)
			
"""----------------------------------------------------------------"""
if __name__ == "__main__":
	main()
"""----------------------------------------------------------------"""			
			
	
