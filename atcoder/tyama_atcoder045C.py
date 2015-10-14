#!/usr/bin/python
from collections import defaultdict
import sys
if sys.version_info[0]>=3: raw_input=input
sys.setrecursionlimit(10**7)

N,X=map(int,raw_input().split())
tree=defaultdict(list)
h=defaultdict(int)
for _ in range(N-1):
	a,b,c=map(int,raw_input().split())
	tree[a].append((b,c))
	tree[b].append((a,c))

def d(c,p,x):
	global tree,h
	r=h[X^x]
	h[x]+=1
	for e,y in tree[c]:
		if p!=e: r+=d(e,c,x^y)
	return r
print(d(1,-1,0))