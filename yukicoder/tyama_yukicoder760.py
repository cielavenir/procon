#!/usr/bin/python
import sys,math,numpy
def thirdPoint(a):
	xdiff=a[1][0]-a[0][0]
	ydiff=a[1][1]-a[0][1]
	return [a[1][0]-ydiff,a[1][1]+xdiff]

xa,ya,ta=map(float,sys.stdin.readline().split())
ta*=math.pi/180
before_=[]
for _ in range(2): before_.append(list(map(float,sys.stdin.readline().split()))+[1])
before_.append(thirdPoint(before_)+[1])
before=numpy.array(before_).transpose()
after_=[]
for _ in range(2): after_.append(list(map(float,sys.stdin.readline().split()))+[1])
after_.append(thirdPoint(after_)+[1])
after=numpy.array(after_).transpose()
r=before.dot(numpy.linalg.inv(after)).dot([[math.cos(ta),-math.sin(ta),xa],[math.sin(ta),math.cos(ta),ya],[0,0,1]])
print(' '.join('%.12f'%e for e in [r[0][2],r[1][2],math.atan2(r[1][0],r[0][0])*180/math.pi]))
dist1=math.hypot(before_[1][0]-before_[0][0],before_[1][1]-before_[0][1])
dist2=math.hypot(after_[1][0]-after_[0][0],after_[1][1]-after_[0][1])
sys.stderr.write('%r\n'%dist1)
sys.stderr.write('%r\n'%dist2)