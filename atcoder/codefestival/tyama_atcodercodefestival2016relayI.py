#!/usr/bin/python
N=input()
if N<3:print -1;exit()
a=range(1,N)
for i in range(N):
	print ' '.join(str(e+(i<e))for e in a)
	a=a[-1:]+a[:-1]
