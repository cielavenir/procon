#!/usr/bin/python
import sys
if sys.version_info[0]>=3:
	raw_input=input
	from functools import reduce
h={}
N=int(raw_input())
for i in range(N):
	a=raw_input().split()
	h[a[0]]=reduce(lambda x,y:x+y,[float(e) for e in a[1:]])
print('%.2f'%(h[raw_input().rstrip()]/3))