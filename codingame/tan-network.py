#!/usr/bin/python
from collections import defaultdict
import sys,csv,math,heapq
if sys.version_info[0]>=3: raw_input=input
INF=1<<30

def calcdist(x,y):
	if x==y: return 0
	lat1,lon1=map(lambda e:float(e)*math.pi/180,[V[x][0],V[x][1]])
	lat2,lon2=map(lambda e:float(e)*math.pi/180,[V[y][0],V[y][1]])
	#a=(lon2-lon1)*math.cos((lat1+lat2)/2)
	#b=(lat2-lat1)
	#return math.hypot(a,b)*6371
	#oh oh oh ^_^
	return 6371*math.acos( (math.sin(lat1)*math.sin(lat2)+math.cos(lat1)*math.cos(lat2)*math.cos(lon1-lon2)) )

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

def buildPath(prev, t):
	path=[]
	u=t
	while u>=0:
		path.append(u)
		u=prev[u]
	return list(reversed(path))

start,end=[raw_input().strip() for _ in range(2)]
v=int(raw_input())
_V=list(csv.reader([raw_input() for _ in range(v)]))
mapping={e[0]:i for i,e in enumerate(_V)}
mapping_rev={v:k for k,v in mapping.items()}
V={e[0]:[e[3],e[4],e[1]] for e in _V}
g=int(raw_input())
_G=[raw_input().split() for _ in range(g)]
G=defaultdict(list)
for e in _G:
	x,y=e
	G[mapping[x]].append([calcdist(x,y),mapping[x],mapping[y]])
	#directed...
	#G[mapping[y]].append([calcdist(x,y),mapping[y],mapping[x]])

dist=[INF]*len(V)
prev=[-1]*len(V)
shortestPath(G,mapping[start],dist,prev)
if dist[mapping[end]]==INF:
	print('IMPOSSIBLE')
else:
	for e in buildPath(prev,mapping[end]):
		print(V[mapping_rev[e]][2])