#!/usr/bin/python
import sys,numpy
if sys.version_info[0]>=3: raw_input=input
n,m=map(int,raw_input().split())

a=[]
for _ in range(n):
	a.append([int(e) for e in raw_input().split()])
a=numpy.array(a)
b=[]
for _ in range(n):
	b.append([int(e) for e in raw_input().split()])
b=numpy.array(b)

for e in ['add','subtract','multiply','divide','mod','power']:
	print(getattr(numpy,e)(a,b))