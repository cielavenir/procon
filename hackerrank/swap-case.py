#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
print(''.join(chr(ord(c)^32) if 'a'<=c<='z' or 'A'<=c<='Z' else c for c in raw_input()))