#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input

for _ in range(int(raw_input())):
	a,b=map(int,raw_input().split())
	print(a*b)