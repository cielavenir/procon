#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
a=set(raw_input() for _ in range(int(raw_input())))
print(len(a))