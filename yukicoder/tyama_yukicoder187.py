#!/usr/bin/python
from functools import reduce
import sys
if sys.version_info[0]>=3: raw_input=input

def egcd(x,y):
	if y==0: return (x,1,0)
	g,a,b=egcd(y,x%y)
	return (g,b,a-x//y*b)

def perform(a1,m1,a2,m2):
	g,x,y=egcd(m1,m2)
	if (a2-a1)%g: raise ValueError
	l=m1//g*m2
	return ((a1+(a2-a1)//g*x*m1)%l,l)

def chinese(a):
	if not a: return None
	try:
		return reduce(lambda x,y:perform(*(x+y)),a)
	except ValueError:
		return None

a=[]
for _ in range(int(raw_input())):
	a.append(tuple(int(e) for e in raw_input().split()))
r=chinese(a)
print(r[not r[0]]%(10**9+7) if r else -1)