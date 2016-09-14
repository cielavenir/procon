#!/usr/bin/python
from collections import defaultdict
import sys
h=defaultdict(int)
n=int(sys.stdin.readline())
for _ in range(n):
	r=0
	x,y=sys.stdin.readline().split()
	for c in y:r=r*2+int(c)%2
	if x=='+':
		h[r]+=1
	elif x=='-':
		h[r]-=1
	else:
		print(h[r])