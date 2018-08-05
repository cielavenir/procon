#!/usr/bin/python
from heapq import *
import sys, math

D={
'L':(-1,0),
'D':(0,1),
'R':(1,0),
'U':(0,-1),
}
n,m,k=map(int,sys.stdin.readline().split())
d=sys.stdin.readline().strip()
st=None
go=None
s=[]
for i in range(n):
	line=sys.stdin.readline().strip()
	j=line.find('S')
	if j>=0: st=[i,j]
	j=line.find('G')
	if j>=0: go=[i,j]
	s.append(line)

#calculate cost table
costs=[{} for _ in range(k)]
for i in range(k):
	o=i
	z=0
	costs[i][d[o]]=z
	i-=1
	if i==-1:i=k-1
	z+=1
	while d[o]!=d[i]:
		costs[i][d[o]]=z
		i-=1
		if i==-1:i=k-1
		z+=1

#bfs
depth={}
q=[[0]+st]
while q:
	cur=heappop(q)
	curcost=cur.pop(0)
	if tuple(cur) in depth: continue
	depth[tuple(cur)]=curcost
	if cur==go:
		print(curcost)
		exit()
	for (_d,(dx,dy)) in D.items():
		if _d not in costs[curcost%k]: continue
		ncost=costs[curcost%k][_d]+curcost+1
		nx=cur[1]+dx
		ny=cur[0]+dy
		if 0<=nx<m and 0<=ny<n and s[ny][nx]!='#' and not math.isinf(ncost):
			heappush(q,[ncost,ny,nx])
print(-1)
