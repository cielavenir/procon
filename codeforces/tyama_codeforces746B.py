#!/usr/bin/python
import sys
if sys.version_info[0]<3: input=raw_input

input();s=input().strip();k=len(s)%2;print(s[k::2][::-1]+s[k^1::2])