#!/usr/bin/python
from functools import reduce
import sys,operator
if sys.version_info[0]>=3: raw_input=input
h=set()
f=10
x=0
for i,c in enumerate(raw_input().rstrip()):
	if i==0 and not('0'<=c<='9'):
		f=9
	if c=='?':
		x+=1
	elif 'A'<=c<='J':
		h.add(c)
r=reduce(operator.mul,range(11-len(h),11),1)
if x>0:
	r*=10
	x-=1
r=r*f//10
print(str(r)+'0'*x)