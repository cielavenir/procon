#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
x=raw_input()
if sys.version_info[0]>=3:
	print(raw_input().translate(str.maketrans('','',x)))
else:
	print(raw_input().translate(None,x))