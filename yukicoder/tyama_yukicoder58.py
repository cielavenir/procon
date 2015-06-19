#!/usr/bin/python
N=input()
K=input()
s=0.
t=7**7
r=__import__('random').randrange
for _ in[0]*t:
	a=0
	for i in range(N):a+=r(1,7)-r(4 if i<K else 1,7)
	s+=a<0
print s/t