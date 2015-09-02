#!/usr/bin/python
from collections import defaultdict
import sys
if sys.version_info[0]>=3: raw_input=input
raw_input()
d=defaultdict(int)
for e in raw_input().split(): d[int(e)]+=1
r=0
for _ in range(int(raw_input())):
	x,y=map(int,raw_input().split())
	if d[x]:
		d[x]-=1
		r+=y
print(r)