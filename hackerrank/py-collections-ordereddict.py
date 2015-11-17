#!/usr/bin/python
from collections import defaultdict
import sys
if sys.version_info[0]>=3: raw_input=input
d=defaultdict(int)
for _ in range(int(raw_input())):
	a=raw_input().split()
	n=int(a.pop())
	d[' '.join(a)]+=n
for k in sorted(d):
	print(k+' '+str(d[k]))