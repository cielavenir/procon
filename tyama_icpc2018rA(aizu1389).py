#!/usr/bin/python
def solve(s,t):
	idx=0
	while idx<len(s):
		if s[idx].isdigit(): break
		idx+=1
	if t[:idx]<s[:idx]:
		return '-'
	elif t[:idx]>s[:idx] or s==t:
		return '+'
	elif len(t)==idx:
		return '-'
	elif len(s)==idx or not t[idx].isdigit():
		return '+'
	else:
		a=''
		idx2=idx
		while idx2<len(s) and s[idx2].isdigit():
			a+=s[idx2]
			idx2+=1
		a=int(a)
		b=''
		idx2=idx
		while idx2<len(t) and t[idx2].isdigit():
			b+=t[idx2]
			idx2+=1
		b=int(b)
		if a==b:
			return solve(s[idx2:],t[idx2:])
		else:
			return '-' if a>b else '+'

import sys
n=int(sys.stdin.readline())
s=sys.stdin.readline().strip()
for _ in range(n):
	t=sys.stdin.readline().strip()
	print(solve(s,t))
