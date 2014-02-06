#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
raw_input()
print(sorted(set([int(e) for e in raw_input().split()]),key=lambda e: -e)[1])