#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
for _ in range(int(raw_input())):
	#do it twice
	print(raw_input().replace(' || ',' or ').replace(' && ',' and ').replace(' || ',' or ').replace(' && ',' and '))