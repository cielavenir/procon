#!/usr/bin/python
import sys,math
if sys.version_info[0]>=3: raw_input=input
N=int(raw_input())
for i in range(N):
	x1,y1,x2,y2,x3,y3=[float(e) for e in raw_input().split()]
	a1=2*x2-2*x1
	b1=2*y2-2*y1
	c1=x1*x1-x2*x2+y1*y1-y2*y2
	a2=2*x3-2*x1
	b2=2*y3-2*y1
	c2=x1*x1-x3*x3+y1*y1-y3*y3
	x=(b1*c2-b2*c1)/(a1*b2-a2*b1)
	y=(c1*a2-c2*a1)/(a1*b2-a2*b1)
	print('%.3f %.3f %.3f'%(x,y,math.hypot(x1-x,y1-y)))