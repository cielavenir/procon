#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
z=[]
for i in range(int(raw_input())):
	s=raw_input().rstrip()[-10:]
	z.append('+91 '+s[0:5]+' '+s[5:])
z.sort()
for e in z:print(e)