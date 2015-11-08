#!/usr/bin/python
from __future__ import print_function
import sys,scipy.stats
if sys.version_info[0]>=3: raw_input=input

x=[]
y=[]
try:
	while True:
		a,b=map(float,raw_input().split())
		x.append(a)
		y.append(b)
except EOFError:
	pass

slope, intercept, r_value, p_value, std_err = scipy.stats.linregress(x,y)
print('%.3f %.3f'%(intercept,slope))

'''
15 10
12 25
8 17
8 11
7 13
7 17
7 20
6 13
5 9
3 15
'''