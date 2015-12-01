#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
#for i in range(1,int(raw_input())+1): print(str().join(str(e) for e in list(range(1,i))+list(range(i,0,-1))))
for i in range(1,int(raw_input())+1): print((10**i-1)**2//81)