#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
a=[1,1,2]
for i in range(3,31): a.append(a[i-1]+a[i-2]+a[i-3])
while True:
	n=int(raw_input())
	if n==0: break
	print((a[n]+3649)//3650)