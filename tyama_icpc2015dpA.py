#!/usr/bin/python
import sys,math
if sys.version_info[0]>=3: raw_input=input
while True:
	a,b=[int(e) for e in raw_input().split()]
	if not a: break
	print(min(abs(b-math.hypot(i,a-i)) for i in range(a//2+1)))