#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
a,b=map(int,raw_input().split())
print(a+b)