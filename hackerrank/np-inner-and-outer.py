#!/usr/bin/python
import sys,numpy
if sys.version_info[0]>=3: raw_input=input
a=[int(e) for e in raw_input().split()]
b=[int(e) for e in raw_input().split()]
print(numpy.inner(a,b))
print(numpy.outer(a,b))