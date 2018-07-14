#!/usr/bin/python
class Ternary:
	def __init__(self,n): 
		self.n=n
	def __int__(self):
		return self.n
	def __neg__(self):
		return Ternary(2-int(self))
	def __mul__(self,o):
		return Ternary(min(int(self),int(o)))
	def __add__(self,o):
		return Ternary(max(int(self),int(o)))

import sys, itertools
from functools import reduce
R=[0,1,2]
while True:
	s=sys.stdin.readline().rstrip()
	if s=='.': break
	r=0
	for (a,b,c) in itertools.product(R,repeat=3):
		t=reduce(lambda t,e:t.replace(e[0],'Ternary(%d)'%e[1]),[['0',0],['1',1],['2',2],['P',a],['Q',b],['R',c]],s)
		if int(eval(t))==2: r+=1
	print(r)
