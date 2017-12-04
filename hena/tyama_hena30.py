#!/usr/bin/env python
#http://qiita.com/Nabetani/items/c70417d384720a3339d6
#http://nabetani.sakura.ne.jp/hena/ord30taxi/

DIST={
	'AB':[1090,0],
	'AC':[180,0],
	'AD':[540,1],
	'BC':[960,0],
	'BG':[1270,0],
	'CD':[400,1],
	'CF':[200,0],
	'DE':[720,1],
	'DF':[510,1],
	'EG':[1050,1],
	'FG':[230,1],
}
METER=[
	{'dist':995,'cost':400},{'dist':845,'cost':350}
]
DIFF=[60,50]

def each_cons(iter,n):
	a=[]
	for e in iter:
		if len(a)>=n: a.pop(0)
		a.append(e)
		if len(a)>=n: yield(list(a)) # copy

import sys
while True:
	l=sys.stdin.readline()
	if not l: break
	line=list(each_cons(l.strip(),2))
	cost=dist=0
	meter=METER[int('C'<line[0][0])]
	cost=meter['cost']
	dist=meter['dist']
	for e in line:
		d,color=DIST[''.join(sorted(e))]
		dist-=d
		while dist<0:
			cost+=DIFF[color]
			dist+=200
	print(cost)
	sys.stdout.flush()
