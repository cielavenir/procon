#!/usr/bin/python
import sys,cmath
if sys.version_info[0]>=3: raw_input=input
c=eval(raw_input())
print(abs(c))
print(cmath.phase(c))