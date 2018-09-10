#!/usr/bin/python
import sys,numpy
n=int(sys.stdin.readline())
x=list(range(n))
a=[int(e) for e in sys.stdin.readline().split()]
r=numpy.polyfit(x,a,1)
print('%f %f\n%f'%(r[1],r[0],sum((a-b)**2 for (a,b) in zip(a,numpy.poly1d(r)(x)))))
