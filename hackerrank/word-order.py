#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
h={}
for i in range(int(raw_input())):
	s=raw_input().rstrip()
	if s not in h: h[s]=[i,0]
	h[s][1]+=1
print(len(h))
print(' '.join(str(e[1]) for e in sorted(h.values())))