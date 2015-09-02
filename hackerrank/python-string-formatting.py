#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
n=int(raw_input())
d=1
x=1
while n>=x:
	d+=1
	x*=2
for i in range(1,n+1):
	print('%*d%*o%*X'%(d-1,i,d,i,d,i)+bin(i)[2:].rjust(d))