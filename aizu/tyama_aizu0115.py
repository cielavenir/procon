#!/usr/bin/python
from fractions import Fraction
import sys
if sys.version_info[0]>=3: raw_input=input

def gauss(a):
	if not a or len(a)==0: return None
	n=len(a)
	for i in range(n):
		if a[i][i]==0:
			for j in range(i+1,n):
				if a[j][i]!=0:
					for k in range(i,n+1): a[i][k]+=a[j][k]
					break
			else:
				return None
		for j in range(n):
			if i!=j:
				r = Fraction(a[j][i],a[i][i])
				for k in range(i,n+1): a[j][k] = a[j][k] - a[i][k]*r
	for i in range(n):
		x=Fraction(a[i][i],1)
		for j in range(len(a[i])):
			a[i][j] /= x
	return a

uaz=list(map(int,raw_input().split()))
enemy=[0]+[-x+y for x,y in zip(map(int,raw_input().split()),uaz)]
b0=[1]+[x-y for x,y in zip(map(int,raw_input().split()),uaz)]
b1=[1]+[x-y for x,y in zip(map(int,raw_input().split()),uaz)]
b2=[1]+[x-y for x,y in zip(map(int,raw_input().split()),uaz)]
sol=gauss(list(map(list,zip(b0,b1,b2,enemy,[1,0,0,0]))))
print('MISS' if sol and all(0<=e[-1]<=1 for e in sol) else 'HIT')