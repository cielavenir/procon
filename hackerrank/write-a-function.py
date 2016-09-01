#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input

def is_leap(year):
	if year%400==0: return True
	if year%100==0: return False
	return year%4==0

year = int(raw_input())
print is_leap(year)