#!/usr/bin/python
import sys,itertools
if sys.version_info[0]>=3: raw_input=input
raw_input()
a=raw_input().split()
k=int(raw_input())
num=0
den=0
for e in itertools.permutations(a,k):
	den+=1
	num+='a' in e[:k]
print(num*1.0/den)