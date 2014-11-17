#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input

y=set(range(10))
n=set()
for i in range(int(raw_input())):
	a=raw_input().split()
	if a[-1]=='YES':
		y=y.intersection(set(int(e) for e in a[:-1]))
	else:
		n.update(set(int(e) for e in a[:-1]))
print(list(y-n)[0])