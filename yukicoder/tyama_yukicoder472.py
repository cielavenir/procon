#!/usr/bin/python
from functools import sys
import sys
sys.setrecursionlimit(1000000)
memo={}
def dfs(v,d,r):
	if d==len(v): return 0
	if (d,r) not in memo: memo[(d,r)]=reduce(lambda s,i: min(s,dfs(v,d+1,r-i)+v[d][i]), range(min(r,3)+1), 1<<30)
	return memo[(d,r)]

n,k=map(int,sys.stdin.readline().split())
v=[list(map(int,sys.stdin.readline().split()))+[1] for _ in range(n)]
print(dfs(v,0,k)/float(n))
