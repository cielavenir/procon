#!/usr/bin/python
from __future__ import print_function
from functools import reduce,cmp_to_key
import sys
if sys.version_info[0]>=3: raw_input=input

def compare(x,y):
	if x.islower() or y.islower():
		if x.islower() and y.islower(): return ord(x)-ord(y)
		if x.islower(): return -1
		if y.islower(): return 1
	if x.isupper() or y.isupper():
		if x.isupper() and y.isupper(): return ord(x)-ord(y)
		if x.isupper(): return -1
		if y.isupper(): return 1
	if ord(x)%2==ord(y)%2: return ord(x)-ord(y)
	if ord(x)%2==1: return -1
	if ord(y)%2==1: return 1
	return None

s=raw_input().strip()
print(reduce(lambda x,y:x+y,sorted(s,key=cmp_to_key(compare))))