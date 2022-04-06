"""---------------------------------------------------------------------
Programmer Name : Dhoke Saurabh Vilas 
Script Usage    : compare dates and compare IT Non-IT and read from csv and get todays date
Date            : 13.03.2022
---------------------------------------------------------------------"""

import time
from datetime import date
import pandas as pd

def Compare_dates():
	t = time.localtime()
	current_date = time.strftime("%d/%m",t) 

	File = pd.read_csv('Bday_information.csv')

	list_name    = File.Name
	list_mail_id = File.Mail_id
	list_b_date  = File.B_Date
	list_programmer = File.Programmer


	bday_boy_mid = 0
	it_non_it = "Yes"

	for i in range(0,len(list_b_date),1):
		if current_date == list_b_date[i]:
			bday_boy_mid = list_mail_id[i]
			it_non_it = list_programmer[i]
			
			if it_non_it == "Yes":
				print("-"*100)
				print("It : ",bday_boy_mid)
				fd = open("Bday_wish_programmer.txt",'r')
				BODY = fd.read()
				
				print(BODY)
				fd.close()
				
			else:
				print("-"*100)
				print("Non It : ",bday_boy_mid)
				fd = open("Bday_wish.txt",'r')
				
				BODY = fd.read()
				print(BODY)
				fd.close()
			
			
def main():
	Compare_dates()

if __name__ == "__main__":
	main()
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
