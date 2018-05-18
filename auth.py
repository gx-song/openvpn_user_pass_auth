#!/usr/bin/python2.7

import sqlite3
import os
import sys

username = os.getenv("username")
password = os.getenv("password")
if username is None:
	sys.exit(1)
if password is None:
	sys.exit(1)
conn = sqlite3.connect('auth.db')
c = conn.cursor()
for row in c.execute("select password from auth where username='"+username+"'"):

	print username
	print password
	print row[0]
	if cmp(password,row[0]):
		sys.exit(1)
	
	sys.exit(0)
sys.exit(1)
