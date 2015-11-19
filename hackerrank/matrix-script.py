#!/usr/bin/python
import re,sys
if sys.version_info[0]>=3: raw_input=input

h,w=map(int,raw_input().split())
a=[]
for _ in range(h):a.append(raw_input()[:w])
s=''.join(''.join(e) for e in zip(*a))
t=re.sub(r'([a-zA-Z0-9])([^a-zA-Z0-9]+)(?=[a-zA-Z0-9])',r'\1 ',s)
print(t)