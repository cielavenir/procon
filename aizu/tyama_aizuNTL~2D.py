#!/usr/bin/python
import sys
a,b=map(int,sys.stdin.readline().split())
k=1
if a<0:
	k=-k
	a=-a
if b<0:
	k=-k
	b=-b
print(a//b*k)
