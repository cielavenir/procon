#!/usr/bin/python
import functools
class SAComp:
	def __init__(self,h,g):
		self.h=h
		self.g=g
	def cmp(self,a,b):
		if a==b: return 0
		if self.g[a]!=self.g[b]: return self.g[a]-self.g[b]
		return self.g[a+self.h]-self.g[b+self.h]

def buildSA(t):
	n=len(t)
	g=list(map(ord,t))
	b=[0]*n
	suff=list(range(n))
	comp=SAComp(0,g)
	suff.sort(key=functools.cmp_to_key(comp.cmp))
	h=1
	while b[n-1]!=n-1:
		comp=SAComp(h,g)
		suff.sort(key=functools.cmp_to_key(comp.cmp))
		for i in range(n-1):
			b[i+1]=b[i]+(comp.cmp(suff[i],suff[i+1])<0)
		for i in range(n):
			g[suff[i]]=b[i]
		h<<=1
	return suff

def buildLCP(t,suff):
	n=len(t)
	rank=[0]*n
	lcp=[0]*n
	for i in range(n):
		rank[suff[i]]=i
	h=0
	for i in range(n-1):
		j=suff[rank[i]-1]
		if h>0: h-=1
		while j+h<n and i+h<n and t[j+h]==t[i+h]:
			h+=1
		lcp[rank[i]-1]=h
	return lcp

def solve(s):
	s+='$'
	suff=buildSA(s)
	lcp=buildLCP(s,suff)
	return len(s)-1-max(lcp)

import sys;print(solve(sys.stdin.readline().strip()))
