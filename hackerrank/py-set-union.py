#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
raw_input()
s1=set(map(int,raw_input().split()))
raw_input()
s2=set(map(int,raw_input().split()))
print(len(s1.union(s2)))