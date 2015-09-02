#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
s=raw_input()
for e in ['isalnum','isalpha','isdigit','islower','isupper']: print(any(getattr(c,e)() for c in s))