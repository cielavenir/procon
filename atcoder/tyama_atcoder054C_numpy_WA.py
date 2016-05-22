#!/usr/bin/python
import sys,numpy
m=[map(int,list(e.strip()))for e in sys.stdin]
print ['Even','Odd'][int(round(numpy.linalg.det(m[1:])))%2]