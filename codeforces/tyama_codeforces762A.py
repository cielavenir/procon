#!/usr/bin/python
import sys
n,k=map(int,sys.stdin.readline().split())
r=[]
i=1
while i*i<=n:
	if n%i==0: r.append(i)
	i+=1
q=len(r)*2
if r[-1]**2==n: q-=1
print(-1 if k>q else r[k-1] if k<=len(r) else n//r[q-k])
