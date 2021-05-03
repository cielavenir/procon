#!/usr/bin/python
from functools import reduce
import sys,operator
if sys.version_info[0]>=3: raw_input=input
print(str(reduce(operator.add,map(int,raw_input().split())))+' '+raw_input())