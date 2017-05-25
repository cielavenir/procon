#!/usr/bin/python
import sys
try:
	while True:
		n=int(input())
		c=r=0
		for a,b in sorted([list(map(int,sys.stdin.readline().split())) for _ in range(n)],key=lambda e:e[0] if e[0]<e[1] else 1e10-e[1]):
			c+=a-b
			r=max(r,b+c)
		print(r)
except EOFError:
	pass