#!/usr/bin/python
from __future__ import division
import sys
if sys.version_info[0]>=3: raw_input=input
raw_input()
print(hash(tuple(int(e) for e in raw_input().split())))