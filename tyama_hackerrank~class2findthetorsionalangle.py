#!/usr/bin/python
import sys,math
if sys.version_info[0]>=3: raw_input=input

def plane(a):
	b=[(a[1][i]-a[0][i]) for i in range(3)]
	c=[(a[2][i]-a[0][i]) for i in range(3)]
	return [b[1]*c[2]-c[1]*b[2],b[2]*c[0]-c[2]*b[0],b[0]*c[1]-c[0]*b[1]]
def abs_vec(a):
	return math.sqrt(sum(e**2 for e in a))
def dot_vec(a,b):
	return sum(a[i]*b[i] for i in range(len(a)))

a=[map(float,raw_input().split()) for i in range(4)]
plane1=plane([a[0],a[1],a[2]])
plane2=plane([a[1],a[2],a[3]])
print('%.2f'%(math.acos(dot_vec(plane1,plane2)/abs_vec(plane1)/abs_vec(plane2))*180/math.pi))