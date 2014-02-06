#!/usr/bin/python
from __future__ import division
import sys
if sys.version_info[0]>=3: raw_input=input
a=float(raw_input())
b=float(raw_input())
print('%.2f'%(a+b))
print('%.2f'%(a-b))
print('%.2f'%(a*b))
print('%.2f'%(a/b))
print('%.2f'%(a//b))