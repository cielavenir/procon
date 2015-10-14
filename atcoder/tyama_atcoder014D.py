#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input

import bisect
A,N,M=map(int,raw_input().split())
L=[int(raw_input()) for i in range(N)]
a=sorted(L[i+1]-L[i]-1 for i in range(N-1))
s=[0]
for e in a:s+=[s[-1]+e]
for _ in range(M):
	x,y=map(int,raw_input().split())
	b=bisect.bisect(a,x+y)
	print(N+min(L[0]-1,x)+min(A-L[-1],y)+s[b]+(N-1-b)*(x+y))