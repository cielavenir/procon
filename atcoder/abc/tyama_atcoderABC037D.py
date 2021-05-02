#!/usr/bin/python
import sys
sys.setrecursionlimit(500000)
if sys.version_info[0]>=3:
	xrange=range
	raw_input=input

z=[0,-1,0,1,0]
def dfs(x,y):
	ky=x*H+y
	if not memo[ky]:
		r=1
		for i in xrange(4):
			nx=x+z[i]
			ny=y+z[i+1]
			if 0<=nx<W and 0<=ny<H and M[y][x]<M[ny][nx]:
				r=(r+dfs(nx,ny))%MOD
		memo[ky]=r
	return memo[ky]

H,W=map(int,raw_input().split())
M=[[int(e) for e in raw_input().split()] for _ in xrange(H)]
MOD=10**9+7
memo=[0]*(H*W)
r=0
for y in xrange(H):
	for x in xrange(W):
		r=(r+dfs((x+W//2)%W,(y+H//2)%H))%MOD
print(r)