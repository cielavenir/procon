#!/usr/bin/python
import sys

def f(a,n):
	a=[list(e) for e in a]
	for j in range(len(a)):
		for i in range(n):
			if n+i>=len(a[j]):
				a[j].append(a[j][n-1-i])
			else:
				a[j][n+i]+=a[j][n-1-i]
		a[j]=a[j][n:]
	return a
def g(a,n):
	return list(zip(*f(list(zip(*a)),n)))

while True:
	n,m,t,p=map(int,sys.stdin.readline().split())
	a=[[1]*n for _ in range(m)]
	if n==0: break
	for _ in range(t):
		d,c=map(int,sys.stdin.readline().split())
		a=(f if d==1 else g)(a,c)
	for _ in range(p):
		x,y=map(int,sys.stdin.readline().split())
		print(a[y][x])
