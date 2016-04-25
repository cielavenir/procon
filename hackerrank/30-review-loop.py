#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
for _ in range(int(raw_input())):
    s=raw_input().strip()
    print(' '.join(s[i::2] for i in range(2)))