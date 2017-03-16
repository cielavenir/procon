#!/usr/bin/python
import sys
n,m=map(int,sys.stdin.readline().split())
h=set()
a=[tuple(map(int,sys.stdin.readline().split())) for _ in range(m)]
for e in a: h.add(e)
r=0
for i in range(1,n+1):	
	for j in range(1,n+1):
		r+=sum((i,k) in h and (k,j) in h for k in range(1,n+1))**2
print(r)
