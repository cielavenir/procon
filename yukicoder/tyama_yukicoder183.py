#!/usr/bin/python
import sys
if sys.version_info[0]>=3:raw_input=input
h=[1]+[0]*32768
raw_input()
for e in map(int,raw_input().split()):
 for i in range(32768):h[e^i]|=h[i]
print(sum(h))