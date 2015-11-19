#!/usr/bin/python
from __future__ import print_function
import re,sys
if sys.version_info[0]>=3: raw_input=input

s=raw_input().strip()
print(bool(re.search(r'^[1-9][0-9]{5}$',s) and len(re.findall(r'(.)(?=.\1)',s))<2))