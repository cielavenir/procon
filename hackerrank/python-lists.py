#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
L=[]
for i in range(int(raw_input())):
	a=raw_input().split()
	if a[0]=='print':print(L)
	elif a[0]=='index':print(L.index(int(a[1])))
	elif a[0]=='count':print(L.count(int(a[1])))
	else: getattr(L,a[0])(*map(int,a[1:]))