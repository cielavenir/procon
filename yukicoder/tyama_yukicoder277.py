#!/usr/bin/python
from collections import defaultdict
import sys
if sys.version_info[0]>=3: raw_input=input
sys.setrecursionlimit(10**6)

def dfs(n,d,z):
	r=None
	for e in H[n]:
		if e not in z:
			z[e]=1
			if r is None: r=1<<29
			x=dfs(e,d+1,z)
			r=min(r,x+1)
			del z[e]
	if r is None: r=0
	R[n]=min(r,d)
	L[n]=r
	return r

def dfs2(n,d,z):
	for e in H[n]:
		if e not in z:
			z[e]=1
			dfs2(e,min(d,L[n])+1,z)
			del z[e]
	R[n]=min(R[n],d)

n=int(raw_input())
H=defaultdict(list)
R={}
L={}
for _ in range(n-1):
	x,y=map(int,raw_input().split())
	H[x].append(y)
	H[y].append(x)

dfs(1,0,{1:1})
dfs2(1,0,{1:1})
for i in range(1,n+1):print(R[i])