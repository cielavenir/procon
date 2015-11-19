#!/usr/bin/python
from __future__ import print_function
import re,sys
if sys.version_info[0]>=3: raw_input=input

for _ in range(int(raw_input())):
	s=raw_input().strip()
	a=re.findall(r'^([4-6]\d{15})$',s) or re.findall(r'^([4-6]\d{3})-(\d{4})-(\d{4})-(\d{4})$',s)
	b=a and not re.search(r'(\d)\1\1\1',''.join(a[0]))
	print('Valid' if b else 'Invalid')