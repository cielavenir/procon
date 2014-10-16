#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
while True:
	n,k,m=[int(e) for e in raw_input().split()]
	if n==0:break
	r=0
	for i in range(1,n):r=(r+k)%i
	print((r+m)%n+1)