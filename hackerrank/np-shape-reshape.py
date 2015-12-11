#!/usr/bin/python
import sys,numpy
if sys.version_info[0]>=3: raw_input=input
a=numpy.array([int(e) for e in raw_input().split()])
print(numpy.reshape(a,(3,3)))