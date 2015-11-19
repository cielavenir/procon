#!/usr/bin/python
from __future__ import print_function
import re,sys
if sys.version_info[0]>=3: raw_input=input

r=re.search(r'([0-9a-zA-Z])\1',raw_input())
print(r.group(1) if r else -1)