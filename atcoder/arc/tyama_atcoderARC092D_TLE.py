#!/usr/bin/python
import sys,bisect
N=int(sys.stdin.readline())
A=[int(e) for e in sys.stdin.readline().split()]
B=[int(e) for e in sys.stdin.readline().split()]
r=0
for b in range(29):
	r0=0
	t=1<<b
	a=sorted(-(e%(2*t)) for e in A)
	for e_ in B:
		e=e_%(2*t)
		#i1=(0...N).bsearch{|i|-a[i]<=-1*t+e}||N
		i1=bisect.bisect_right(a,-1*t+e)
		i2=bisect.bisect_right(a,-2*t+e)
		i3=bisect.bisect_right(a,-3*t+e)
		i4=bisect.bisect_right(a,-4*t+e)
		r0+=i4-i3+i2-i1
	r^=r0%2*t
print(r)
