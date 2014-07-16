#!/usr/bin/python
import sys,heapq
try:
	import rpython.rlib.streamio
	stream=rpython.rlib.streamio.fdopen_as_stream(sys.stdin.fileno(),'r')
	raw_input=stream.readline
	def cmp_lt(x,y): return x < y
	heapq.cmp_lt=cmp_lt
	COMPILE=123456789012
	def compile(a,b,c):
		return ((a+COMPILE)<<18) | (b<<9) | c
	def decompile(a):
		return ((a>>18)-COMPILE,(a>>9)&511,a&511)
except ImportError:
	def compile(a,b,c):
		return (a,b,c)
	def decompile(a):
		return a
	if sys.version_info[0]>=3: raw_input=input

INF=1234567890123456789
def shortestPath(g,dist,prev):
	n = len(g)-1
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
	for s in range(n):
		Q=[]
		heapq.heappush(Q,compile(0,s,s))
		while Q:
			e = decompile(heapq.heappop(Q))
			if prev[s][e[2]]!=-2: continue
			prev[s][e[2]] = e[1]
			for f in g[e[2]]:
				if e[0]<INF and f[0]<INF and dist[s][f[2]] > e[0] + f[0]:
					dist[s][f[2]] = e[0] + f[0]
					heapq.heappush(Q,compile(e[0]+f[0],f[1],f[2]))
		for u in range(n):
			if dist[s][u]<INF: dist[s][u] += h[u] - h[s]
	return True

def entry_point(argv):
	V,E=[int(e) for e in raw_input().rstrip().split(' ')]
	g=[[] for i in range(V+1)]
	dist=[[INF]*V for i in range(V)]
	prev=[[-2]*V for i in range(V)]
	for i in range(V): g[i].append([0,i,i])
	for i in range(V): g[V].append([0,V,i])
	for i in range(E):
		s,t,e=[int(e) for e in raw_input().rstrip().split(' ')]
		g[s].append([e,s,t])
	if not shortestPath(g,dist,prev):
		print("NEGATIVE CYCLE")
	else:
		for i in range(V):
			print(' '.join(["INF" if dist[i][j]>=INF else str(dist[i][j]) for j in range(V)]))
	return 0

def target(*args):
	return entry_point

if __name__ == '__main__': entry_point([])