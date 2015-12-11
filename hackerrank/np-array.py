#!/usr/bin/python
import sys,numpy
if sys.version_info[0]>=3: raw_input=input
print(numpy.array(list(reversed(map(float,raw_input().split())))))