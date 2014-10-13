#!/usr/bin/python
#coding:utf-8
import sys
if sys.version_info[0]>=3: raw_input=input
for i in range(int(raw_input())):
	s=raw_input().rstrip()
	if s[0:3]=='???':
		print(s.replace('???',"It's"))
	else:
		print(s.replace('???','its'))