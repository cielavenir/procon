#!/usr/bin/python
import sys
N,M=map(int,sys.stdin.readline().split())
E=N;c=[0]*300000;l=[0]*300000
A=list(map(int,sys.stdin.readline().split()))
def Z(e):
	global E
	p=e-c[e]
	c[e]+=1
	if p>0:
		if not l[p]: E-=1
		l[p]+=1
for e in A:Z(e)
A=[0]+A
for m in range(M):
	x,y=map(int,sys.stdin.readline().split())
	p=A[x]-c[A[x]]+1
	c[A[x]]-=1
	if p>0:
		l[p]-=1
		if not l[p]: E+=1
	A[x]=y
	Z(A[x])
	print(E)
