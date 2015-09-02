#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
for i in range(int(raw_input())):
	try:
		x,y=map(int,raw_input().split())
		print(x//y)
	except ValueError as e:
		print("Error Code: "+str(e))
	except ZeroDivisionError as e:
		print("Error Code: "+str(e))