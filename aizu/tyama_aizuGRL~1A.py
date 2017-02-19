#!/usr/bin/python
from collections import defaultdict
import sys,math,heapq
if sys.version_info[0]>=3: raw_input=input
INF=1<<30

def shortestPath(g,s,dist,prev):
	n = len(g)
	dist[s] = 0
	Q=[]
	heapq.heappush(Q,(0,-2,s))
	while Q:
		e=heapq.heappop(Q)
		if prev[e[2]]!=-1: continue
		prev[e[2]]=e[1]
		for f in g[e[2]]:
			if dist[f[2]]>e[0]+f[0]:
				dist[f[2]]=e[0]+f[0]
				heapq.heappush(Q,(e[0]+f[0],f[1],f[2]))

V,E,R=map(int,raw_input().split())
dist=[INF]*V
prev=[-1]*V
G=defaultdict(list)
for _ in range(E):
	s,t,d=map(int,raw_input().split())
	G[s].append([d,s,t])
	G[s].append([d,t,s])
shortestPath(G,R,dist,prev)
for e in dist:
	print('INF' if e==INF else e)
