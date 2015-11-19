#!/usr/bin/python
from __future__ import print_function
import re,sys
if sys.version_info[0]>=3: raw_input=input

for e in re.split(r'[,\.]',raw_input().strip()): e and print(e)