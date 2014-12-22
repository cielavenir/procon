#!/usr/bin/python
import sys,re
if sys.version_info[0]>=3: raw_input=input

def check(email):
	return re.match(r'^[0-9a-zA-Z\-_]+@[0-9a-zA-Z]+\.[a-zA-Z]{1,3}$',email)

print(sorted(e for e in [raw_input().rstrip() for i in range(int(raw_input()))] if check(e)))