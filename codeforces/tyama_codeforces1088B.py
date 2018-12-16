#!/usr/bin/python
import sys
a=list(map(int,sys.stdin.read().split()))
n=a.pop(0);k=a.pop(0)
a=iter(sorted(set(a)))
q=0
for _ in [0]*k:
	x=next(a,q)
	print(x-q)
	q=x
