#!/usr/bin/python
from __future__ import print_function
import sys,heapq
n,q=map(int,sys.stdin.readline().split())
a=[[] for _ in range(n)]
for _ in range(q):
  g=list(map(int,sys.stdin.readline().split()))
  if g[0]==0:
    heapq.heappush(a[g[1]],-g[2])
  elif g[0]==1:
    a[g[1]] and print(-a[g[1]][0])
  else:
    a[g[1]] and heapq.heappop(a[g[1]])
