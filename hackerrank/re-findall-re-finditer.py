#!/usr/bin/python
from __future__ import print_function
import re,sys
if sys.version_info[0]>=3: raw_input=input

a=re.findall(r'[QWRTYPSDFGHJKLZXCVBNMqwrtypsdfghjklzxcvbnm]([AEIOUaeiou]{2,})(?=[QWRTYPSDFGHJKLZXCVBNMqwrtypsdfghjklzxcvbnm])',raw_input().strip())
if a:
	for e in a: print(e)
else:
	print(-1)