#!/usr/bin/python
import sys,numpy
if sys.version_info[0]>=3: raw_input=input
n,m,p=map(int,raw_input().split())
a=[]
for _ in range(n+m):
	a.append([int(e) for e in raw_input().split()])
a=numpy.array(a)
print(a)