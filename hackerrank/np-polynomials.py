#!/usr/bin/python
import sys,numpy
if sys.version_info[0]>=3: raw_input=input
a=numpy.array([float(e) for e in raw_input().split()])
print(numpy.polyval(a,float(raw_input())))