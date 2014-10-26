#!/usr/bin/python
n=int(raw_input())
h=set()
for a0 in xrange(2,n+1):
	a=a0*a0
	for b in xrange(2,n+1):
		h.add(a)
		a*=a0
print(len(h))
# 100