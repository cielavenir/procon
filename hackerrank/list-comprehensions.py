#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input

def dfs(v,d,a,n):
	if d==len(v):
		if sum(a)!=n: yield a
	else:
		for i in range(v[d]+1):
			for e in dfs(v,d+1,a+[i],n): yield e

v=[int(raw_input()) for i in range(4)]
n=v.pop()
print(list(dfs(v,0,[],n)))