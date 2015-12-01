#!/usr/bin/python
from __future__ import print_function
import sys
if sys.version_info[0]>=3: raw_input=input
raw_input();a=map(int,raw_input().split())
print(all(e>0 for e in a) and any(str(e)==str(e)[::-1] for e in a))