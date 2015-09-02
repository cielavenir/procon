#!/usr/bin/python
import sys,textwrap
if sys.version_info[0]>=3: raw_input=input
s=raw_input().rstrip()
print(textwrap.fill(s,int(raw_input())))