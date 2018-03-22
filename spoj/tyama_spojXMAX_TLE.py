#!/usr/bin/python
import sys
if sys.version_info[0]<3: range=xrange

B=62
def solve(a):
	idx=0
	for i in range(B-1,-1,-1):
		maxI=idx
		maxE=-1
		for j in range(idx,len(a)):
			if a[j]&(1<<i) and a[j]>maxE:
				maxE=a[j]
				maxI=j
		if maxE<0: continue
		a[idx],a[maxI]=a[maxI],a[idx]
		maxI=idx
		for j in range(len(a)):
			if j!=maxI and a[j]&(1<<i):
				a[j]=a[j]^a[maxI]
		idx+=1
	r=0
	for e in a: r^=e
	return r

a=[int(e) for e in sys.stdin.read().split()]
print(solve(a[1:]))
