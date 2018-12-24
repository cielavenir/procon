#!/usr/bin/python
import sys,math,random
import numpy
def thirdPoint(a):
	xdiff=a[1][0]-a[0][0]
	ydiff=a[1][1]-a[0][1]
	return [a[1][0]-ydiff,a[1][1]+xdiff]

lim=(-10000,10000)
while True:
	xa=random.randint(lim[0],lim[1]) # uniform
	ya=random.randint(lim[0],lim[1])
	ta=random.randint(0,359)
	xb=random.randint(lim[0],lim[1])
	yb=random.randint(lim[0],lim[1])
	tb=random.randint(0,359)
	ta*=math.pi/180
	tb*=math.pi/180
	before_=[]
	for _ in range(2):
		a=[random.randint(lim[0],lim[1]) for _ in range(2)]
		before_.append(a+[1])
	before_.append(thirdPoint(before_)+[1])
	dist1=math.hypot(before_[1][0]-before_[0][0],before_[1][1]-before_[0][1])
	before=numpy.array(before_).transpose()
	r=numpy.array(
		[[math.cos(ta),-math.sin(ta),xa],[math.sin(ta),math.cos(ta),ya],[0,0,1]]
	).dot(numpy.linalg.inv(
		[[math.cos(tb),-math.sin(tb),xb],[math.sin(tb),math.cos(tb),yb],[0,0,1]]
	)).dot(
		before
	).transpose()
	pts=[e[0:2] for e in r[0:2]]
	if all(lim[0]<=f[0]<=lim[1] and lim[0]<=f[1]<=lim[1] for f in pts):
		sys.stderr.write('%d %d %d\n'%(xb,yb,tb))
		sys.stdout.write('%d %d %d\n'%(xa,ya,ta))
		for f in before_[0:2]:
			sys.stdout.write('%d %d\n'%tuple(f[0:2]))
		vec=pts[1]-pts[0]
		dist2=math.hypot(vec[0],vec[1])
		sys.stderr.write('%r\n'%dist1)
		sys.stderr.write('%r\n'%dist2)
		for e in pts:
			sys.stdout.write(' '.join('%.15f'%f for f in e)+'\n')
		break
