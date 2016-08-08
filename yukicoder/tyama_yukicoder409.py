#!/usr/bin/python
#This code does not check the correctness of the algorithm.

import sys
if sys.version_info[0]>=3: raw_input=input

#http://stackoverflow.com/questions/4544630/automatically-growing-lists-in-python
class GrowingList(list):
	def __init__(self,val=None):
		self.val=val
	def __getitem__(self, index):
		if index >= len(self):
			return self.val
		return list.__getitem__(self, index)
	def __setitem__(self, index, value):
		if index >= len(self):
			self.extend([self.val for _ in range(index + 1 - len(self))])
		list.__setitem__(self, index, value)

def is_minimam(a1,b1,a2,b2,a3,b3):
	return (a2-a1)*(b3-b2)>=(b2-b1)*(a3-a2)

def is_maximam(a1,b1,a2,b2,a3,b3):
	return is_minimam(-a1,-b1,-a2,-b2,-a3,-b3)

def check(l1,l2,l3):
	return is_minimam(l1[0],l1[1],l2[0],l2[1],l3[0],l3[1])

def calc(l,now):
	return l[0]*now+l[1]

class ConvexHullTrick:
	def __init__(self):
		self.deque=GrowingList([0,0])
		self.s=0
		self.t=0
	def add(self,a,b):
		l=[a,b]
		while self.s+1<self.t and check(self.deque[self.t-2],self.deque[self.t-1],l):
			self.t-=1
		self.deque[self.t]=l
		self.t+=1
	def get(self,now):
		while self.s+1<self.t and calc(self.deque[self.s],now)>=calc(self.deque[self.s+1],now):
			self.s+=1
		return calc(self.deque[self.s],now)

n,a,b,w=map(int,raw_input().split())
deq=ConvexHullTrick()
z = w + 0 * a + b * 0 * (0 - 1) // 2
deq.add( - 0 * b, z)
r = z - a * (n - 0) + b * (n - 0) * (n - 0 + 1) // 2
for i,e in enumerate(raw_input().split()):
	z = int(e) - i * a + ( b * i * (i + 1)) // 2 + deq.get(i)
	deq.add( - (i + 1) * b , z + (i + 1) * a + ( b * (i + 1) * i) // 2)
	r = min(r,z - a * (n -(i+1)) + b * (n - (i+1)) * (n - (i+1) + 1) // 2)
print(r)