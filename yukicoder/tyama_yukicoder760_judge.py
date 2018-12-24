#!/usr/bin/python
import sys,math,random
import numpy
def thirdPoint(a):
	xdiff=a[1][0]-a[0][0]
	ydiff=a[1][1]-a[0][1]
	return [a[1][0]-ydiff,a[1][1]+xdiff]

with open(sys.argv[1]) as f:
	xa,ya,ta=map(float,f.readline().split())
	ta*=math.pi/180
	before_=[]
	for _ in range(2): before_.append(list(map(float,f.readline().split()))+[1])
	before_.append(thirdPoint(before_)+[1])
	before=numpy.array(before_).transpose()
	after_=[]
	for _ in range(2): after_.append(list(map(float,f.readline().split()))+[1])
	#after_.append(thirdPoint(after_)+[1])

xb,yb,tb=map(float,sys.stdin.readline().split())
tb*=math.pi/180

r=numpy.array(
	[[math.cos(ta),-math.sin(ta),xa],[math.sin(ta),math.cos(ta),ya],[0,0,1]]
).dot(numpy.linalg.inv(
	[[math.cos(tb),-math.sin(tb),xb],[math.sin(tb),math.cos(tb),yb],[0,0,1]]
)).dot(
	before
).transpose()
for i,e in enumerate(r[0:2]):
	sys.stderr.write('%.15f\n'%math.hypot(after_[i][0]-e[0],after_[i][1]-e[1]))
	assert math.hypot(after_[i][0]-e[0],after_[i][1]-e[1])<1e-2
