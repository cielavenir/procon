#!/usr/bin/python
import sys
if sys.version_info[0]>=3: xrange=range

M=17
def mul(a,b):
	r=[[0]*len(b[0]) for _ in xrange(len(a))]
	for y in xrange(len(a)):
		for x in xrange(len(b[0])):
			r[y][x]=sum(a[y][i]*b[i][x] for i in xrange(len(b)))%M
	return r

A=[[1,1,1,1],[1,0,0,0],[0,1,0,0],[0,0,1,0]]
E=[[1,0,0,0],[0,1,0,0],[0,0,1,0],[0,0,0,1]]
for _ in xrange(int(sys.stdin.readline())):
	n=int(sys.stdin.readline())
	a=A
	e=E
	while n:
		if n%2: e=mul(a,e)
		a=mul(a,a)
		n//=2
	print(e[-1][-1])
