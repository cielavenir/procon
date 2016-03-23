#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
n=int(raw_input())
a=[int(e) for e in raw_input().split()]
ma=max(a)
mi=min(a)
b=[i for i in range(n) if a[i]==ma]
c=[i for i in range(n) if a[i]==mi]
r=n
for b0 in b:
	for c0 in c:
		r=min(r,abs(b0-c0)+1)
print(r)