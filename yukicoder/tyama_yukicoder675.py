#!/usr/bin/python
import copy,math
try:
	import numpy
	def mul(a,b):
		return numpy.array(a).dot(b)
except ImportError:
	def mul(a,b):
		assert len(a[0])==len(b)
		r=[[0]*len(b[0]) for _ in a]
		for i in range(len(a)):
			for j in range(len(b[0])):
				for k in range(len(a[0])):
					r[i][j]+=a[i][k]*b[k][j]
		return r

n,x,y=map(int,raw_input().split())
a=[[[1,0,c[1]],[0,1,0],[0,0,1]] if c[0]==1 else [[1,0,0],[0,1,c[1]],[0,0,1]] if c[0]==2 else [[0,1,0],[-1,0,0],[0,0,1]] for c in [map(int,raw_input().split()) for _ in range(n)]]
for i in range(n-2,-1,-1): a[i]=mul(a[i+1],a[i])
for i in range(n): print ' '.join(map(str,zip(*mul(a[i],[[x],[y],[1]]))[0][:2]))
