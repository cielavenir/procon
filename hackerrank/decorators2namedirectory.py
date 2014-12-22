#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
z=[]
for i in range(int(raw_input())):
	a=raw_input().split()
	x='Mr.' if a.pop()=='M' else 'Ms.'
	n=int(a.pop())
	z.append([n,i,' '.join([x]+a)])
z.sort()
for e in z:print(e[2])