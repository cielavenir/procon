#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
h={}
N=int(raw_input())
for i in range(N):
	a=raw_input().rstrip()
	b=float(raw_input())
	if b not in h: h[b]=[]
	h[b].append(a)
keys=sorted(h.keys())
for e in sorted(h[keys[1]]): print(e)