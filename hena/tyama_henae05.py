#!/usr/bin/env python
#http://qiita.com/Nabetani/items/c516875b13a4d282affe
#http://nabetani.sakura.ne.jp/hena/orde05dokitruck/

T={
	1:{0:[0,1],1:[1,2],2:[2]},
	2:{0:[0,2],1:[1],2:[1,2]},
	3:{0:[0,2],1:[0,1],2:[2]},
	4:{0:[0],1:[0,1],2:[1,2]},
	5:{0:[0],1:[1,2],2:[0,2]},
	6:{0:[0,1],1:[1],2:[0,2]},
	7:{0:[0],1:[],2:[2]},
	8:{0:[],1:[1],2:[2]},
	9:{0:[0],1:[1],2:[]},
}

def dfs(d,cur):
	if d==len(line): return True
	if (d,cur) not in m: m[(d,cur)]=any(dfs(d+1,e) for e in T[line[d]][cur])
	return m[(d,cur)]

import sys
while True:
	l=sys.stdin.readline()
	if not l: break
	line=list(map(int,l.strip()))
	m={}
	r=''.join(chr(e+97) for e in range(3) if dfs(0,e))
	print(r or "-")
	sys.stdout.flush()
