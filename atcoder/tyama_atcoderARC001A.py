#!/usr/bin/python
from __future__ import print_function
import sys
if sys.version_info[0]>=3: raw_input=input
raw_input()
s=list(raw_input())
a=[s.count(e) for e in iter('1234')]
print(max(a),min(a))