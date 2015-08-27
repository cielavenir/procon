#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
n=int(raw_input())
s=set(map(int, raw_input().split()))
for _ in range(int(raw_input())):
	a=raw_input().split()
	if a[0]=='pop':
		s.pop()
	elif a[0]=='discard':
		s.discard(int(a[1]))
	elif a[0]=='remove':
		s.remove(int(a[1]))
print(sum(s))