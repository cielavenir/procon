#!/usr/bin/python
import numpy
from sys import stdin
M=10**9+7
N=int(stdin.readline())
c=numpy.zeros(5000, numpy.intp)
for i in range(N):c[int(stdin.readline())]+=1
a=numpy.zeros(N+1, numpy.intp);a[0]=1
f=a.copy()
for i in range(N):
	f[i+1] = f[i]*-~i%M
	a[1:] = (a[1:] + a[:-1]*c[i])%M
r=0
for i in range(N+1):r=(r+(-1)**(i%2)*a[i]*f[N-i])%M
print r