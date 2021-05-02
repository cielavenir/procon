#!/usr/bin/python
def shortestPath(g,s,dist,prev):
	n = len(g)-1
	Q=[]
	heapq.heappush(Q,(0,-2,s))
	while Q:
		e = heapq.heappop(Q)
		if prev[e[2]]!=-1: continue
		prev[e[2]] = e[1]
		for f in g[e[2]]:
			if dist[f[2]] > e[0] + f[0]:
				dist[f[2]] = e[0] + f[0]
				heapq.heappush(Q,(e[0]+f[0],f[1],f[2]))

import sys,heapq
if sys.version_info[0]>=3:raw_input=input

n=int(raw_input())
g=[[] for _ in range(n+1)]
for _ in range(n-1):
	a,b=map(int,raw_input().split())
	g[a-1]+=[(1,a-1,b-1)]
	g[b-1]+=[(1,b-1,a-1)]
z=[-1]*n
for _ in range(int(raw_input())):
	a,b=map(int,raw_input().split())
	g[n]+=[(b,n,a-1)]
	z[a-1]=b
a=[1e9]*n+[0]
shortestPath(g,n,a,[-1]*(n+1))

r=''
for _ in g:
	if any(e[1]!=n and abs(a[e[1]]-a[e[2]])!=1 for e in _):r='No'
if any(z[i]>=0 and z[i]!=a[i] for i in range(n)):r='No'
print(r or "Yes\n"+"\n".join(map(str,a[:n])))
