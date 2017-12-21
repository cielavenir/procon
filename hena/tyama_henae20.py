#!/usr/bin/env python
#https://qiita.com/Nabetani/items/7baf181b4a1b7eacc79a
#http://nabetani.sakura.ne.jp/hena/orde20maze/
from scipy.sparse import *
t='01 23 34 45 06 17 39 5B 78 89 9A 6C 9F CD FG CI EK GM HN JK KL LM IO JP MS NT PQ QR ST PV RX SY UV VW YZ'
T=tuple(zip(*[[int(c,36) for c in e] for e in t.split()]))

import sys
while True:
	l=sys.stdin.readline()
	if not l: break
	line=[int(c,36) for c in l.strip()]
	a=csgraph.dijkstra(csr_matrix(([1]*len(T[0]),T),[36]*2),0,line[0])
	print(int(a[line[1]]))
	sys.stdout.flush()
