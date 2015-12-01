#!/usr/bin/python
import sys,itertools
if sys.version_info[0]>=3: raw_input=input
print(' '.join('('+str(len(list(e[1])))+', '+str(e[0])+')' for e in itertools.groupby(raw_input().strip())))