#!/usr/bin/python
from __future__ import division
import sys
if sys.version_info[0]>=3: raw_input=input
a=int(raw_input())
for i in range(a):print(i*i)