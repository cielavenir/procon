#!/usr/bin/python
import sys,numpy
if sys.version_info[0]>=3: raw_input=input
n=int(raw_input())
a=[]
for _ in range(n):
	a.append([float(e) for e in raw_input().split()])
a=numpy.array(a)
print(numpy.linalg.det(a))