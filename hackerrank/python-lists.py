#!/usr/bin/python
from __future__ import division
import sys
if sys.version_info[0]>=3: raw_input=input
L=[]
for i in range(int(raw_input())):
	a=raw_input().split()
	if a[0]=='append':L+=[int(a[1])]
	if a[0]=='extend':L+=[int(e) for e in a[1:]]
	if a[0]=='insert':L.insert(int(a[1]),int(a[2]))
	if a[0]=='remove':L.remove(int(a[1]))
	if a[0]=='pop':L.pop()
	if a[0]=='index':print(L.index(int(a[1])))
	if a[0]=='count':print(L.count(int(a[1])))
	if a[0]=='sort':L.sort()
	if a[0]=='reverse':L.reverse()
	if a[0]=='print':print(L)