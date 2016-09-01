#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input

s=raw_input().strip()
k=int(raw_input())
l=len(s)//k
for i in range(l):
	t=''
	for c in s[i*k:i*k+k]:
		if c not in t: t+=c
	print(t)