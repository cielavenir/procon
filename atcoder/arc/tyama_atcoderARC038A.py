#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
raw_input()
a=sorted(map(int,raw_input().split()))
print(max(sum(a[::2]),sum(a[1::2])))