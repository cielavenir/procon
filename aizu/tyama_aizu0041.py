#!/usr/bin/python

import sys,itertools
if sys.version_info[0]>=3: raw_input=input

def dfs(a):
	if len(a)<2: yield (a[0],str(a[0]))
	for i in range(len(a)-1):
		for l in dfs(a[:i+1]):
			for r in dfs(a[i+1:]):
				yield (l[0]+r[0],'(%s + %s)'%(l[1],r[1]))
				yield (l[0]-r[0],'(%s - %s)'%(l[1],r[1]))
				yield (l[0]*r[0],'(%s * %s)'%(l[1],r[1]))

def solve(a):
	for e in itertools.permutations(a):
		for n,s in dfs(e):
			if n==10:
				print(s)
				return True

try:
	while True:
		a=[int(e) for e in raw_input().split()]
		if a==[0,0,0,0]: break
		if not solve(a): print(0)
except EOFError:
	pass