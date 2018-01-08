#!/usr/bin/python
#works with Py2/3 and use numpy only if available.

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

#def dist(a,b):
#	return math.sqrt(sum((a[i]-b[i])**2 for i in range(len(a))))

def rotateTriangle(*_):
	d=copy.deepcopy(list(_))
	for i in range(len(d)-1,-1,-1):
		d[i][0]-=d[0][0]
		d[i][1]-=d[0][1]
		d[i][2]-=d[0][2]
	d=list(zip(*d))
	thetay=-math.atan2(d[2][1],d[0][1])
	d=mul([[math.cos(thetay),0,-math.sin(thetay)],[0,1,0],[math.sin(thetay),0,math.cos(thetay)]],d)
	thetaz=-math.atan2(d[1][1],d[0][1])
	d=mul([[math.cos(thetaz),-math.sin(thetaz),0],[math.sin(thetaz),math.cos(thetaz),0],[0,0,1]],d)
	thetax=-math.atan2(d[2][2],d[1][2])
	d=mul([[1,0,0],[0,math.cos(thetax),-math.sin(thetax)],[0,math.sin(thetax),math.cos(thetax)]],d)
	d=list(zip(*d))
	return [e[0:2] for e in d]

import sys
a=[list(map(float,sys.stdin.readline().split())) for _ in range(4)]
for e in a:
	assert(all(-1e6<=f<=1e6 for f in e))
b=rotateTriangle(*a)
if True:
	for i in range(3):
		edgex=b[(i+1)%3][0]-b[i][0]
		edgey=b[(i+1)%3][1]-b[i][1]
		vx=b[3][0]-b[i][0]
		vy=b[3][1]-b[i][1]
		if edgex*vy-edgey*vx<0:
			print('NO')
			exit()
	print('YES')
else:
	def cross(a,b):
		return (a.conjugate()*b).imag
	def dot(a,b):
		return (a.conjugate()*b).real
	def norm(a):
		return a.real**2+a.imag**2
	def projection(a,b,p):
		t = dot(p-a, a-b) / norm(a-b);
		return a + t*(a-b)
	def distanceLP(a,b,p):
		return abs(p - projection(a,b,p))
	b=[complex(e[0],e[1]) for e in b]
	for i in range(3):
		print(distanceLP(b[i],b[(i+1)%3],b[3]))
