#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input

#This is a kind of golf mission; submit only below.
for _ in range(int(raw_input())):
	raw_input();s1=set(map(int,raw_input().split()))
	raw_input();s2=set(map(int,raw_input().split()))
	print(s2==s1.union(s2))