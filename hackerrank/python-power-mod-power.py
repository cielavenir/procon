#!/usr/bin/python
from __future__ import division
import sys
if sys.version_info[0]>=3: raw_input=input
a=int(raw_input())
b=int(raw_input())
m=int(raw_input())
print(pow(a,b))
print(pow(a,b,m))