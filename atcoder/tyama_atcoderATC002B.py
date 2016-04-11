#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
n,m,p=map(int,raw_input().split())
print(pow(n,p,m))