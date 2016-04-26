#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input

M=10**9+7
N,Q=map(int,raw_input().split())
v=list(map(int,raw_input().split()))
d=[0]
for i in range(N-1):d+=[d[i]+pow(v[i],v[i+1],M)]
p=r=0
for x in raw_input().split():x=int(x)-1;r+=abs(d[x]-d[p]);p=x
print((r+d[p])%M)