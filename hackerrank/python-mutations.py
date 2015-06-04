#!/usr/bin/python
from __future__ import division
import sys
if sys.version_info[0]>=3: raw_input=input
s=raw_input()
a,b=raw_input().split()
print(s[0:int(a)]+b+s[int(a)+1:])