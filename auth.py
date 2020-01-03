#!/usr/bin/env python

import sqlite3
import os
import sys

py_ver = sys.version_info.major
username = os.getenv("username")
password = os.getenv("password")
if username is None:
	sys.exit(1)
if password is None:
	sys.exit(1)
conn = sqlite3.connect('auth.db')
c = conn.cursor()
for row in c.execute("select password from auth where username='"+username+"'"):

	print (username)
	print (password)
	print (row[0])
	if (py_ver == 2):
		if cmp(password,row[0]):
			sys.exit(1)
	if (py_ver == 3):
		import operator
		if operator.ne(password,row[0]):
			sys.exit(1)
	sys.exit(0)
sys.exit(1)
