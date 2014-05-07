#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
raw_input()
a=set([int(e) for e in raw_input().split()])
raw_input()
b=set([int(e) for e in raw_input().split()])
for e in sorted(list(a-b)+list(b-a)): print(e)