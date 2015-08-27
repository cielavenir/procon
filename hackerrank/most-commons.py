#!/usr/bin/python
from collections import Counter
import sys
if sys.version_info[0]>=3: raw_input=input
c=Counter(raw_input().rstrip())
i=0
for v,k in sorted((-v,k) for k,v in c.most_common()):
	print k+' '+str(-v)
	i+=1
	if i>=3: break