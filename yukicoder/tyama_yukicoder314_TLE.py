#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
sys.setrecursionlimit(1000000)

memo={}
def dfs(k,p,d):
	if k<0 or p<0: return 0
	if d==0: return 1
	x=tuple([k,p,d])
	if x not in memo:
		memo[x]=(dfs(k-1,1,d-1)+dfs(2,p-1,d-1))%1000000007
	return memo[x]

n=int(raw_input())
print(dfs(2,0,n))