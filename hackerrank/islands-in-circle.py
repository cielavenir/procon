#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input

n,k=[int(e) for e in raw_input().split()]
print(min(n if n%2 else n//2,(k%2==0)+(k+1)//2*2))