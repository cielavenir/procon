#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
N,X=map(int,raw_input().split())
for e in zip(*[[float(e) for e in raw_input().split()] for _ in range(X)]):
	print('%.1f'%(sum(e)/len(e)))