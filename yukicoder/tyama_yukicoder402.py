#!/usr/bin/python
from __future__ import division,print_function
import sys
if sys.version_info[0]<3: input=raw_input

h,w=map(int,input().split())
S=[[ord(c)<46 for c in e]for e in sys.stdin]
for y in range(1,h):
 for x in range(1,w):S[y][x]+=min(S[y-1][x-1],S[y][x-1],S[y-1][x])*S[y][x]
print(-~max(max(e)for e in S)//2)