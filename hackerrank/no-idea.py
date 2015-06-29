#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
raw_input()
X=[int(e) for e in raw_input().split()]
A={int(e) for e in raw_input().split()}
B={int(e) for e in raw_input().split()}
r=0
for e in X:
	r+=(e in A)-(e in B)
print(r)