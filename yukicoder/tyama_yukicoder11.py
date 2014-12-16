#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input

w=int(raw_input())
h=int(raw_input())
n=int(raw_input())
a=[set() for i in range(2)]
for _ in range(n):
	for i,e in enumerate(map(int,raw_input().split())):
		a[i].add(e)
print(len(a[0])*h+len(a[1])*w-len(a[0])*len(a[1])-n)