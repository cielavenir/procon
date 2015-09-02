#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
N,M=map(int,raw_input().split())
a=[('.|.'*i).center(M,'-') for i in range(1,N,2)]
for e in a+['WELCOME'.center(M,'-')]+list(reversed(a)):print(e)