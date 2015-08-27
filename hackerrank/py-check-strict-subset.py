#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
chk=lambda s,t:s==s.union(t) and s!=t
s=set(map(int,raw_input().split()))
print all(chk(s,set(map(int,raw_input().split()))) for _ in range(int(raw_input())))