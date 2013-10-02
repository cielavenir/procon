#!/usr/bin/python
from __future__ import print_function
from collections import Counter
import sys
if sys.version_info[0]>=3: raw_input=input
for k,v in Counter(raw_input().split()).items(): print(k,v)