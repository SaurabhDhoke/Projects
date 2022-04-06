"""---------------------------------------------------------------------
Programmer Name : Dhoke Saurabh Vilas 
Script Usage    : This Script is used to send mail
Date            : 01.02.2022
---------------------------------------------------------------------"""

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

"""---------------------------------------------------------------------"""		

def is_connected():
	try:
		urlopen('https://www.google.com/')
		return True
	except:
		return False
"""---------------------------------------------------------------------"""		

def MailSender(time):
	try:
		from_address = "thisissaurabhdhoke@gmail.com"
		to_address = "saurabhdhoke70@gmail.com"
		
		msg = MIMEMultipart()
		msg['From'] = from_address
		msg['To'] = to_address

		body = """
		Hey Hii Friend 
		
		You are one of the best programmers i know..what makes you even more special is that you are also one of the my best friend 💕️.
		
		Hope your birthday loops run smoothly and that you dont break out of the for loop too soon.🤩️
		
		I Hope your age gets incremented without bugs....😍️✌️
		
		You have written hundreds of thousands of lines of code, but you have never lost a single semicolon. You are the best programmer i have ever seen..😂️
		
		Wish you a Happy B day.... 💌️🍷️🎂️🍻️
		
		This is auto generated mail...
		
		Thanks & Regards,
		Dhoke Saurabh
			"""

		
		Subject = """
		B-Day Wishes 
		"""
		
		msg['Subject'] = Subject
		msg.attach(MIMEText(body,'plain'))
		
		"""this code is used to attach file fromn dir
		attachment = open(filename,"rb")
		
		p = MIMEBase('application','octet-stream')
		p.set_payload((attachment).read())
		
		encoders.encode_base64(p)
		p.add_header('Content-Disposition')
		msg.attach(p)"""
			
		s = smtplib.SMTP('smtp.gmail.com',587)
		s.starttls()
		s.login(from_address,"30883088")
		
		text = msg.as_string()
		s.sendmail(from_address,to_address,text)
		s.quit()
		print("Mail successfully sent")

	except Exception as E:
		print("Unable to send mail",E)
	
	print()
"""---------------------------------------------------------------------"""		
		
def Mail():	
	connected = is_connected()
	
	if connected :
		startTime = time.time()
		MailSender(time.ctime())
		endTime = time.time()
		
		print('Took %s seconds to send mail'%(endTime - startTime))
	else:
		print("There is no internet Connection")	
	print()	
	
"""-------------------------------------------------------------------------------"""	

def main():
	print("-------------- Shiv Shambho : Mail Sender Script ------------------")
	
	print("Application Name : "+argv[0])
	
	
	if(len(argv) >= 2):
		if(argv[1] == "-h" or argv[1] == "-H"):
			print("This script is used to send mail")
			exit()
	
		if(argv[1] == "-u" or argv[1] == "-U"):
			print("Usage : Application_Name  Time_to_send_mail_in_minutes")	
			exit()

	schedule.every(int(argv[1])).minutes.do(Mail)
	while True:
		schedule.run_pending()
		time.sleep(int(argv[1]))		
	
	"""	
	try:
		schedule.every(int(argv[1])).minutes.do(Mail)
		while True:
			schedule.run_pending()
			time.sleep(int(argv[1]))
			
	except Exception:
		print("Error : Invalid input")
	"""

"""---------------------------------------------------------------------"""		
if __name__ == "__main__":
	main()
"""---------------------------------------------------------------------"""		
	
