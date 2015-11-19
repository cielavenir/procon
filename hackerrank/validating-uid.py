#!/usr/bin/python
from __future__ import print_function
import re,sys
if sys.version_info[0]>=3: raw_input=input

for _ in range(int(raw_input())):
	s=raw_input().strip()
	print('Valid' if re.search(r'[A-Z].*[A-Z]',s) and re.search(r'[0-9].*[0-9].*[0-9]',s) and re.search(r'^[0-9a-zA-Z]{10}$',s) and not re.search(r'(.).*\1',s) else 'Invalid')