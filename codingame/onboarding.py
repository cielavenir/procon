#!/usr/bin/python
import sys

if sys.version_info[0]>=3: raw_input=input
while 1:
	n=int(raw_input())
	mi=9999999
	name=''
	for i in range(n):
		enemy,dist=raw_input().split()
		if mi>float(dist):
			mi=float(dist)
			name=enemy
	print(name)