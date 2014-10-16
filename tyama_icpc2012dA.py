#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input

n=int(raw_input())
for i in range(0,n):
	y,m,d=[int(e) for e in raw_input().split()]
	y-=1;m-=1
	print(196471-y*195-y//3*5-m*20+(m//2 if y%3!=2 else 0)-d)