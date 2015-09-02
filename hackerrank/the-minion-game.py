#!/usr/bin/python
from collections import defaultdict
import sys
if sys.version_info[0]>=3: raw_input=input
r=[0,0]
s=raw_input().strip()
for i,c in enumerate(s): r[c in 'AEIOU']+=len(s)-i
if r[0]>r[1]:
	print('Stuart %d'%r[0])
elif r[0]<r[1]:
	print('Kevin %d'%r[1])
else:
	print('Draw')