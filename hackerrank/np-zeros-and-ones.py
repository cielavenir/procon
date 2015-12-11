#!/usr/bin/python
import sys,numpy
if sys.version_info[0]>=3: raw_input=input
a=[int(e) for e in raw_input().split()]
print(numpy.zeros(tuple(a),dtype=numpy.int))
print(numpy.ones(tuple(a),dtype=numpy.int))