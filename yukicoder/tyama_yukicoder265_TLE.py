#!/usr/bin/python

import re

def add(a,b):
	m=max(len(a),len(b))
	return [(0 if len(a)<=i else a[i])+(0 if len(b)<=i else b[i]) for i in range(m)]

def sub(a,b):
	return add(a,[-1*e for e in b])

def mul(a,b):
	r=[]
	for i in range(len(b)):
		r=add(r,[0]*i+[b[i]*e for e in a])
	return r

def dif(a):
	if len(a)<=1: return [0]
	return [i*a[i] for i in range(1,len(a))]

def process(s):
	'''
	try:
		while True:
			bidx=s.index('(')
			count=1
			eidx=bidx+1
			while count>0:
				if s[eidx]=='(': count+=1
				if s[eidx]==')': count-=1
				eidx+=1
			s=s[:bidx]+process(s[bidx+1:eidx-1])+s[eidx:]
	except ValueError:
		pass
	'''
	try:
		while True:
			bidx=s.index('d')
			count=1
			eidx=bidx+2
			while count>0:
				if s[eidx]=='{': count+=1
				if s[eidx]=='}': count-=1
				eidx+=1
			s=s[:bidx]+','.join(str(f) for f in dif([int(e) for e in process(s[bidx+2:eidx-1]).split(',')]))+s[eidx:]
	except ValueError:
		pass
	while True:
		m=re.match(r'(.*?)([0-9,-]+)([*])([0-9,-]+)(.*)',s)
		if not m: break
		s=m.group(1)+','.join(str(f) for f in mul([int(e) for e in m.group(2).split(',')],[int(e) for e in m.group(4).split(',')]))+m.group(5)
	while True:
		m=re.match(r'(.*?)([0-9,-]+)([+Z])([0-9,-]+)(.*)',s)
		if not m: break
		if m.group(3)=='+':
			s=m.group(1)+','.join(str(f) for f in add([int(e) for e in m.group(2).split(',')],[int(e) for e in m.group(4).split(',')]))+m.group(5)
		else:
			s=m.group(1)+','.join(str(f) for f in sub([int(e) for e in m.group(2).split(',')],[int(e) for e in m.group(4).split(',')]))+m.group(5)
	return s

if __name__ == '__main__':
	import sys
	if sys.version_info[0]>=3: raw_input=input
	raw_input()
	d=int(raw_input())
	s=raw_input().rstrip().replace('-','Z').replace('x','0,1')
	r=process(s).split(',')
	r+=['0']*(d+1-len(r))
	print(' '.join(r))