#!/usr/bin/python
import sys,numpy
if sys.version_info[0]>=3: raw_input=input
n,m=map(int,raw_input().split())
print(numpy.eye(n, m, k = 0))