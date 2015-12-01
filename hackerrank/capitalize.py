#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
print(' '.join(e[0].upper()+e[1:].lower() if e else '' for e in raw_input().split(' ')))