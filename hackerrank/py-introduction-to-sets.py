#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
raw_input()
a=set(map(int,raw_input().split()))
print(sum(a)*1.0/len(a))