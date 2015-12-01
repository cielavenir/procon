#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
print(''.join(str(e) for e in range(1,int(raw_input())+1)))