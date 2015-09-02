#!/usr/bin/python
import sys,itertools
if sys.version_info[0]>=3: raw_input=input
a=list(map(int,raw_input().split()))
b=list(map(int,raw_input().split()))
print(' '.join(str(e) for e in itertools.product(a,b)))