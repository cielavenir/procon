#!/usr/bin/python
from __future__ import print_function
from fractions import Fraction
import sys,itertools

def dfs(a):
	if len(a)<2: yield a[0]
	for i in range(len(a)-1):
		for l in dfs(a[:i+1]):
			for r in dfs(a[i+1:]):
				if l==r: print('YES');exit(0)
				if l<r: continue
				yield l+r
				yield l-r
				yield l*r
				yield Fraction(l,r)

n=int(sys.stdin.readline())
a=list(map(int,sys.stdin.readline().split()))
for b in itertools.permutations(a):
	for e in dfs(b): pass
print('NO')
