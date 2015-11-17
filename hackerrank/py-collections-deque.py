#!/usr/bin/python
from collections import deque
import sys
if sys.version_info[0]>=3: raw_input=input
q=deque()
for _ in range(int(raw_input())):
	a=raw_input().split()
	getattr(q,a[0])(*map(int,a[1:]))
print(' '.join(map(str,q)))