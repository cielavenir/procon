#!/usr/bin/python
from collections import defaultdict
import sys,heapq

H=defaultdict(dict)
N,M,Q=map(int,sys.stdin.readline().split())
for i in range(M):
	x,y=map(int,sys.stdin.readline().split())
	x-=1;y-=1
	H[x][y]=H[y][x]=0
for i in range(Q):
	x,y=map(int,sys.stdin.readline().split())
	x-=1;y-=1
	H[x][y]=H[y][x]=Q-i

#dijkstra-like
A=[0]+[-1]*(N-1)
q=[[0,0]]
while q:
	cost1,src=heapq.heappop(q)
	for dst,cost2 in H[src].items():
		cost=max(cost1,cost2)
		if A[dst]<0 or cost<A[dst]:
			A[dst]=cost
			heapq.heappush(q,[cost,dst])

for i in range(1,N):
	if A[i]<0:
		print(0)
	elif A[i]==0:
		print(-1)
	else:
		print(Q-A[i]+1)