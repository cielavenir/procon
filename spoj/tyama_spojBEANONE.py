#!/usr/bin/python
from functools import reduce
import sys
if sys.version_info[0]>=3: raw_input=input
n=int(raw_input())+3
print(reduce(lambda x,y:x*y,range(1,n+1))-n*n+1)