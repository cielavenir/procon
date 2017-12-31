#!/usr/bin/env python
import sys
n,k,*a=map(int,sys.stdin.read().split())
bag=[0]+[-float('inf')]*k
for e in a:
	for i in range(k,e-1,-1):bag[i]=max(bag[i],bag[i-e]+e)
print(max(bag))
