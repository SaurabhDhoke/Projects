"""---------------------------------------------------------------------
Programmer Name : Dhoke Saurabh Vilas 
Script Usage    : separate the columns
Date            : 13.03.2022
---------------------------------------------------------------------"""


import pandas as pd

File = pd.read_csv('Bday_information.csv')

print("-"*100)

list_name    = File.Name
list_mail_id = File.Mail_id
list_b_date  = File.B_Date

print(list_name)
print("-"*100)

print(list_mail_id)
print("-"*100)

print(list_b_date)
print("-"*100)









