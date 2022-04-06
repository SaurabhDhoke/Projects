
"""--------------------------------------------------------------------------------------------------------------------------------------------
---- Program Name : BDay_Wish 
---- Description  : This script is used to wish freinds by mail on there b day and names of b day boys are written in log file and send this log file to owner by using mail
---- Input  : -
---- Output : create log file of bday boys and whish those b day boys and send this log to to the owner by using mail 
---- Auther : Saurabh Vilas Dhoke
---- Date   : 14.03.2022
------------------------------------------------------------------------------------------------------------------------------------------------"""

"""---------------------------------------------------------------------------------------------------------------------------------------------
---- Neccesary modules are imported below
------------------------------------------------------------------------------------------------------------------------------------------------"""

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

"""---------------------------------------------------------------------------------------------------------------------------------------------
---- Function Name : is_connected 
---- Description   : Returns True if pc have internet connection otherwise False   
---- Input  : -
---- Output : True / False
---- Auther : Saurabh Vilas Dhoke
---- Date   : 15.03.2022
------------------------------------------------------------------------------------------------------------------------------------------------"""

def is_connected():
	try:
		urlopen('https://www.google.com/')
		return True
	except:
		return False

"""----------------------------------------------------------------------------------------------------------------------------------------------
---- Function Name : Mail 
---- Description   : if pc have internet connection then this function calls MailSender() function else print No internet Connection.   
---- Input  : bday_boy_mid  = mail id 
----		  BODY 		    = Mail body readed from txt file
----		  bb_name	    = Name of BDay Boy 
----		  FD 			= FD of log file
---- Output : if True it Calls MailSender() function else print no Internet
---- Auther : Saurabh Vilas Dhoke
---- Date   : 16.03.2022
------------------------------------------------------------------------------------------------------------------------------------------------"""

def Mail(bday_boy_mid,BODY,bb_name,FD):	
	connected = is_connected()
	
	if connected :
		MailSender(bday_boy_mid,BODY,bb_name,FD)
	else:
		print("There is no internet Connection...connect Wifi to PC and then Run the script")	
	
	print()	

"""------------------------------------------------------------------------------------------------------------------------------------------------
---- Function Name : MailSender 
---- Description   : send bday wish to bday boy and write name of bday boy into a log file    
---- Input  : bday_boy_mid  = mail id of bday boy 
----		  BODY 	    	= Mail body readed from txt file
----		  bb_name	    = Name of BDay Boy 
----		  FD 			= FD of log file
---- Output : Send bday wish to bday boy and write bb_name into log file
---- Auther : Saurabh Vilas Dhoke
---- Date   : 16.03.2022
------------------------------------------------------------------------------------------------------------------------------------------------"""

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
		FD.write(bb_name + "\t"+ bday_boy_mid + "\n")  # it write name of bb_name and mail id into log file

	except Exception as E:
		print("Unable to send mail",E)

"""------------------------------------------------------------------------------------------------------------------------------------------------
---- Function Name : MailSender_Owner 
---- Description   : this function sends the information to the owner to whome script wishes happy bday today means log file.    
---- Input  : filename ...(log file name)
---- Output : this function send log to the owner 
---- Auther : Saurabh Vilas Dhoke
---- Date   : 16.03.2022
------------------------------------------------------------------------------------------------------------------------------------------------"""

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

		Subject = """Report to Owner about to whome script wishes today..."""
		
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

"""------------------------------------------------------------------------------------------------------------------------------------------------
---- Function Name : Compare_dates 
---- Description   : this function reads csv file and comapair todays date with B_Date column if date matched then it calls Mail() function and send mail_id, Name and BODY of mail. and it also create one log file of name Wish_on_todaysdate , if there no ones bday today it write into log file as there no bday . And finaly it call the MailSender_Owner() function and pass parameter as  log file name.    
---- Input  : -
---- Output : if today have any ones bday then it calls mail() function and 
---- Auther : Saurabh Vilas Dhoke
---- Date   : 16.03.2022
------------------------------------------------------------------------------------------------------------------------------------------------"""

def Compare_dates():
	""" it stores starting time of application """
	startTime = time.time()    
	
	t = time.localtime()
	current_date = time.strftime("%d/%m",t) 
	
	"""	By using pandas module data is read into File Variable	"""
	File = pd.read_csv('Bday_information.csv')

	""" Data from column copy into separate lists """
	list_name       = File.Name
	list_mail_id    = File.Mail_id
	list_b_date     = File.B_Date
	list_programmer = File.Programmer

	bday_boy_mid = 0
	it_non_it = "Yes"  # BDay_boy is of IT fild or not 

	""" if there is no folder of Sended_Wishes then create that folder for storing log files """
	folder_name = "Sended_Wishes"
	if not os.path.exists(folder_name):
		try:
			os.mkdir(folder_name)
		except:
			pass
	
	""" Log file created into Sended_Wishes folder with date stamp"""
	today = date.today()
	log_path = os.path.join(folder_name,"Wish_on %s.txt"%(today))
	
	separator = "-" * 58
	
	""" open log file write time stamp into file """
	FD = open(log_path,'w')
	FD.write(separator + "\n")
	FD.write("\nLog file created at : "+time.ctime() + "\n\n")
	
	FD.write(separator + "\n")
	FD.write("\nBelow mentioned boys and girls are born on todays date  \n\n")
	FD.write(separator + "\n")

	flag = False
	""" Compare list of birthdate with todays date """
	for i in range(0,len(list_b_date),1):
		if(current_date == list_b_date[i]): 
			bday_boy_mid = list_mail_id[i]         
			it_non_it    = list_programmer[i]      
			bb_name      = list_name[i]			   
			flag = True
			
			""" copy mail_id  of bday_boy 
			    Get it is IT or Non_IT (Yes/No)
			    copy Name of bday_boy """
			
			"""
			 if bday boy is Programmer then text from Bday_wish_programmer.txt 
			 file readed and store in body and that BODY is send to Mail() function 
			 
			 else bday boy is non-programmer then txt from Bday_wish_non_Programmer.txt
			 file readed and store in body and that BODY is send to Mail() function  
			"""
		
			if (it_non_it == "Yes"):
				fd = open("Bday_wish_programmer.txt",'r')   
				BODY = fd.read()
				fd.close()
				Mail(bday_boy_mid,BODY,bb_name,FD)
				
			else:
				fd = open("Bday_wish_non_Programmer.txt",'r')	
				BODY = fd.read()
				fd.close()
				Mail(bday_boy_mid,BODY,bb_name,FD)
	
	""" if flag remain False then there is no date is matched with todays date there no BDay_Boy today """
	if(flag == False):
		FD.write("Today there is No B-day Boy"+ "\n")
	
	""" endTime stores Ending time of application """
	endTime = time.time()	    	
	FD.write(separator + "\n")
	
	""" it write into log file how many seconds time get to run this script """
	FD.write('Took %s seconds to Run this script.' %(endTime - startTime) + "\n")   
	FD.write(separator + "\n")
	
	""" log file closed """
	FD.close()   
	
	""" call to mailsender_owner function and pass log file path"""
	MailSender_Owner(log_path)	
			
"""------------------------------------------------------------------------------------------------------------------------------------------------
---- Function Name : main 
---- Description   : Executing of script starts from here , Every 24 hr it calls Compare_dates() function   
---- Input  : -
---- Output : Call Compare_dates() function 
---- Auther : Saurabh Vilas Dhoke
---- Date   : 16.03.2022
------------------------------------------------------------------------------------------------------------------------------------------------"""
			
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
			""" Sleep of 24 hr """
		
		except ValueError:
			print("Error : Invalid datatype of input")
		except Exception as E:
			print("Error : Invalid input",E)
			
"""------------------------------------------------------------------------------------------------------------------------------------------------
---- Description   : Starter    
---- Input  : -
---- Output : call the main() function
---- Auther : Saurabh Vilas Dhoke
---- Date   : 16.03.2022
------------------------------------------------------------------------------------------------------------------------------------------------"""

if __name__ == "__main__":
	main()

"""------------------------------------------------------------------------------------------------------------------------------------"""			
			
	
