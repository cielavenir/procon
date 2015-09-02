#!/usr/bin/python
import sys,itertools
if sys.version_info[0]>=3: raw_input=input
K,M=map(int,raw_input().split())
a=[[int(e)**2 for e in raw_input().split()][1:] for _ in range(K)]
print(max(sum(e)%M for e in itertools.product(*a)))