#!/usr/bin/python
import sys,numpy
n=int(sys.stdin.readline())
a=list(map(float,sys.stdin.readline().split()))
b=list(map(float,sys.stdin.readline().split()))
print('%.3f'%numpy.corrcoef(a,b)[0,1])
