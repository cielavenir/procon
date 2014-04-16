#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
s=raw_input().rstrip()
print("Correct" if len(s)>=5 and any(e.islower() for e in s) and any(e.isupper() for e in s) and any(e.isdigit() for e in s) else "Too weak")