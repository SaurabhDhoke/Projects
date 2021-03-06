
"""--------------------------------------------------------------------------------------------------------------------------------------------
---- Program Name : Festival Wishes
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
---- Date   : 01/04/2022
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
---- Input  : Friend_mid  = mail id 
----		  BODY 		    = Mail body readed from txt file
----		  F_name	    = Name of Friend
----		  FD 			= FD of log file
---- Output : if True it Calls MailSender() function else print no Internet
---- Auther : Saurabh Vilas Dhoke
---- Date   : 16.03.2022
------------------------------------------------------------------------------------------------------------------------------------------------"""

def Mail(Friend_mid,BODY,F_name,FD):	
	connected = is_connected()
	
	if connected :
		MailSender(Friend_mid,BODY,F_name,FD)
	else:
		print("There is no internet Connection...connect Wifi to PC and then Run the script \n")	
	

"""------------------------------------------------------------------------------------------------------------------------------------------------
---- Function Name : MailSender 
---- Description   : send bday wish to bday boy and write name of bday boy into a log file    
---- Input  : Friend_mid    = mail id
----		  BODY 	    	= Mail body readed from txt file
----		  f_name	    = Name of freind
----		  FD 			= FD of log file
---- Output : Send wish to freinds and write f_name into log file
---- Auther : Saurabh Vilas Dhoke
---- Date   : 16.03.2022
------------------------------------------------------------------------------------------------------------------------------------------------"""

def MailSender(Friend_mid,BODY,f_name,FD):
	
	try:
		from_address = "thisissaurabhdhoke@gmail.com"
		to_address = Friend_mid
		
		msg = MIMEMultipart()
		msg['From'] = from_address
		msg['To'] = to_address

		body = BODY
		
		Subject = """??????? Festival Wishes ???????"""
		
		msg['Subject'] = Subject
		msg.attach(MIMEText(body,'plain'))
		
		"""------------ Attach image ----------------------"""
		
		photo = "Gudhi_Padava.jpg"
		
		attachment = open(photo,"rb")
		
		p = MIMEBase('application','octet-stream')
		p.set_payload((attachment).read())
		
		encoders.encode_base64(p)
		p.add_header('Content-Disposition',"attachment;filename =  %s"%photo)
		msg.attach(p)
		
		"""--------------------------------------------------"""
		
		s = smtplib.SMTP('smtp.gmail.com',587)
		s.starttls()
		s.login(from_address,"30883088")
		
		text = msg.as_string()
		s.sendmail(from_address,to_address,text)
		s.quit()
		FD.write(f_name + '\t' + Friend_mid + '\n') 

	except Exception as E:
		print("Unable to send mail",E)

"""------------------------------------------------------------------------------------------------------------------------------------------------
---- Function Name : MailSender_Owner 
---- Description   : this function sends the information to the owner to whome script wishes today means log file.    
---- Input  : filename ...(log file name)
---- Output : this function send log to the owner 
---- Auther : Saurabh Vilas Dhoke
---- Date   : 01/04/2022
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
---- Description   : this function reads csv file and it also create one log file of name Wish_on_todaysdate And finaly it call the MailSender_Owner() function and pass parameter as  log file name.    
---- Input  : -
---- Output : it calls mail() function
---- Auther : Saurabh Vilas Dhoke
---- Date   : 01/04/2022
------------------------------------------------------------------------------------------------------------------------------------------------"""

def Start_Code():
	startTime = time.time()    
	
	t = time.localtime()
	current_date = time.strftime("%d/%m",t) 
	
	File = pd.read_csv('Bday_information.csv')

	list_name       = File.Name
	list_mail_id    = File.Mail_id
	
	folder_name = "Sended_Wishes"
	if not os.path.exists(folder_name):
		try:
			os.mkdir(folder_name)
		except:
			pass
	
	today = date.today()
	log_path = os.path.join(folder_name,"Wish_on %s.txt"%(today))
	
	separator = "-" * 58
	
	FD = open(log_path,'w')
	FD.write(separator + "\n")
	FD.write("\nLog file created at : "+time.ctime() + "\n\n")
	
	FD.write(separator + "\n")
	FD.write("\nScript Sended Festival Wishes to Below mentioned boys and girls \n\n")
	FD.write(separator + "\n")

	
	for i in range(0,len(list_name),1):
		
		Friend_mid = list_mail_id[i]         
		F_name = list_name[i]
		
		fd = open("Wishes.txt",'r')   
		BODY = fd.read()
		fd.close()
		Mail(Friend_mid,BODY,F_name,FD)
			
				
	endTime = time.time()	    	
	FD.write(separator + "\n")
	
	FD.write('Took %s seconds to Run this script.' %(endTime - startTime) + "\n")   
	FD.write(separator + "\n")
	FD.close()   
	
	MailSender_Owner(log_path)	
			
"""------------------------------------------------------------------------------------------------------------------------------------------------
---- Function Name : main 
---- Description   : Executing of script starts from here . 
---- Input  : -
---- Output : Call () function 
---- Auther : Saurabh Vilas Dhoke
---- Date   : 16.03.2022
------------------------------------------------------------------------------------------------------------------------------------------------"""
			
def main():
	print("\n-------------- Shiv Shambho : Festival Wisher Script ------------------")
	print("Application Name : "+argv[0])
	
	if (len(argv) == 2):
		if ((argv[1] == "-h") or (argv[1] == "-H")):	
			print("This script is used to wish to all freinds on Festivals and write name of friend into log file")
			exit()
			
		if ((argv[1] == "-u") or (argv[1] == "-U")):	
			print("Usage : Application_Name")
			exit()
		
	try:
		startTime = time.time()
		Start_Code()
		endTime = time.time()		
			
		print('Took %s seconds to Run this script.' %(endTime - startTime))
		print("Todays Work is done...\n")
			
		
	except ValueError:
		print("Error : Invalid datatype of input")
	except Exception as E:
		print("Error : Invalid input",E)
		
"""------------------------------------------------------------------------------------------------------------------------------------------------
---- Description   : Starter    
---- Input  : -
---- Output : call the main() function
---- Auther : Saurabh Vilas Dhoke
---- Date   : 01/04/2022
------------------------------------------------------------------------------------------------------------------------------------------------"""

if __name__ == "__main__":
	main()

"""------------------------------------------------------------------------------------------------------------------------------------"""			
			
	
