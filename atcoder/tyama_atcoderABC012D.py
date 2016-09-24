#!/usr/bin/python
import sys,heapq

INF=1234567890123456789
def shortestPath(g,dist,prev):
	n = len(g)-1
	'''
	h = [INF]*n+[0]
	for k in range(n+1):
		for i in range(n+1):
			for e in g[i]:
				if h[e[1]]<INF and e[0]<INF and h[e[2]] > h[e[1]] + e[0]:
					h[e[2]] = h[e[1]] + e[0]
					if k==n: return False # negative cycle
	for i in range(n):
		for e in g[i]:
			e[0]+=h[i]-h[e[2]]
	'''
	for s in range(n):
		Q=[]
		heapq.heappush(Q,(0,s,s))
		while Q:
			e = heapq.heappop(Q)
			if prev[s][e[2]]!=-2: continue
			prev[s][e[2]] = e[1]
			for f in g[e[2]]:
				if dist[s][f[2]] > e[0] + f[0]:
					dist[s][f[2]] = e[0] + f[0]
					heapq.heappush(Q,(e[0]+f[0],f[1],f[2]))
		#for u in range(n):
		#	if dist[s][u]<INF: dist[s][u] += h[u] - h[s]
	return True

def entry_point(argv):
	V,E=[int(e) for e in sys.stdin.readline().rstrip().split(' ')]
	g=[[[0,i,i]] for i in range(V+1)]
	g[V]=[[0,V,i] for i in range(V)]
	dist=[[INF]*V for i in range(V)]
	prev=[[-2]*V for i in range(V)]
	for i in range(E):
		s,t,e=[int(e) for e in sys.stdin.readline().rstrip().split(' ')]
		g[s-1].append([e,s-1,t-1])
		g[t-1].append([e,t-1,s-1])
	shortestPath(g,dist,prev)
	print( min(max(dist[i][j] for j in range(V)) for i in range(V)) )
	return 0

def target(*args):
	return entry_point, None

if __name__ == '__main__': entry_point([])
