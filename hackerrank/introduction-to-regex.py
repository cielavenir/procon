#!/usr/bin/python
from __future__ import print_function
import re,sys
if sys.version_info[0]>=3: raw_input=input

for _ in range(int(raw_input())):
	s=raw_input().strip()
	print('True' if re.search(r'^[+-]?\d*\.\d+$',s) else 'False')