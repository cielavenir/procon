#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input

def solve(s,t):
	if s==t:
		return 'IDENTICAL'
	s=s.split('"')
	t=t.split('"')
	if len(s)==len(t):
		k0=sum(s[i]!=t[i] for i in range(0,len(s),2))
		k1=sum(s[i]!=t[i] for i in range(1,len(s),2))
		if k0==0 and k1==1:
			return 'CLOSE'
	return 'DIFFERENT'

try:
	while True:
		s=raw_input().strip()
		if s=='.': break
		t=raw_input().strip()
		print(solve(s,t))
except EOFError:
	pass
