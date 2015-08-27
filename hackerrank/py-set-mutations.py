#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
raw_input()
s=set(map(int,raw_input().split()))
for _ in range(int(raw_input())):
	a=raw_input().split()
	getattr(s,a[0])(set(map(int,raw_input().split())))
print(sum(s))