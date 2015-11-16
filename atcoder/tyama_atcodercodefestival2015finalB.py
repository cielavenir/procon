#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input

def probability(n, s):
	a=[0]*(s*(n+1)+1)
	for i in range(1,s+1):
		a[i+s]=1.0/s**n
	for e in range(n-1):
		for i in reversed(range(0,s*n+1)):
			a[i+s]=sum(a[i:i+s])
	return max([e,-i] for i,e in enumerate(a))

n=int(raw_input())
print(-probability(n,6)[1]-6)