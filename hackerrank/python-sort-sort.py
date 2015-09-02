#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
N,M=map(int,raw_input().split())
a=[[int(e) for e in raw_input().split()] for _ in range(N)]
K=int(raw_input())
for e in sorted(a,key=lambda e:e[K]):print(' '.join(map(str,e)))