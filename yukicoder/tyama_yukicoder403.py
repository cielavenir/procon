#!/usr/bin/python
from __future__ import print_function
import sys
if sys.version_info[0]<3: input=raw_input

a,b,c=map(int,input().split('^'))
M=10**9+7
print(pow(pow(a,b,M),c,M),pow(a,pow(b,c,M-1)+M-1,M))