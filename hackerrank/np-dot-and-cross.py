#!/usr/bin/python
import sys,numpy
if sys.version_info[0]>=3: raw_input=input
n=int(raw_input())
a=[]
for _ in range(n):
	a.append([int(e) for e in raw_input().split()])
a=numpy.array(a)
b=[]
for _ in range(n):
	b.append([int(e) for e in raw_input().split()])
b=numpy.array(b)
print(numpy.dot(a,b))