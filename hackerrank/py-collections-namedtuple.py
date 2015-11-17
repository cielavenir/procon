#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input

## 4 lines ##
n=int(input())
t=__import__('collections').namedtuple('t',input().split())
a=[t(*input().split()) for _ in range(n)]
print(sum(float(e.MARKS) for e in a)/n)