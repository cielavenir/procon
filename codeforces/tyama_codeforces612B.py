#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input

n=int(raw_input())
a=[e[1] for e in sorted([int(e),i] for i,e in enumerate(raw_input().split()))]
print(sum(abs(a[i]-a[i+1]) for i in range(n-1)))