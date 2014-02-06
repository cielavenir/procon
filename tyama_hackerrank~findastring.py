#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
s=raw_input().rstrip()
t=raw_input().rstrip()
r=0
for i in range(len(s)-len(t)+1):
	if s[i:i+len(t)]==t: r+=1
print(r)