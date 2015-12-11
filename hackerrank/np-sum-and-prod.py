#!/usr/bin/python
import sys,numpy
if sys.version_info[0]>=3: raw_input=input
n,m=map(int,raw_input().split())
a=[]
for _ in range(n):
	a.append([int(e) for e in raw_input().split()])
a=numpy.array(a)
a=numpy.sum(a, axis = 0)
print(numpy.prod(a, axis = None))