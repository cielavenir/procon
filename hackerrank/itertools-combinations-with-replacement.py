#!/usr/bin/python
import sys,itertools
if sys.version_info[0]>=3: raw_input=input
a,b=raw_input().split()
for e in itertools.combinations_with_replacement(sorted(a),int(b)): print(''.join(e))