from __future__ import division
import sys
if sys.version_info[0]>=3: raw_input=input

X=4
Y=2
i=0
m={}
prev={}
v=[]
for i in range(X*Y): v.append(str(i))
m[''.join(v)]=[0,0]
prev[''.join(v)]=[''.join(v),None]
q=[v]
while len(q)>0:
	v=q.pop(0)
	coor=m[''.join(v)][0]
	x=coor%X
	y=coor//X
	depth=m[''.join(v)][1]
	nextstr=''.join(v)
	if 0<x:
		v[coor],v[coor-1]=v[coor-1],v[coor]
		if ''.join(v) not in m:
			m[''.join(v)]=[coor-1,depth+1]
			q.append(v[:])
			prev[''.join(v)]=[nextstr,'R']
		v[coor],v[coor-1]=v[coor-1],v[coor]
	if x<X-1:
		v[coor],v[coor+1]=v[coor+1],v[coor]
		if ''.join(v) not in m:
			m[''.join(v)]=[coor+1,depth+1]
			q.append(v[:])
			prev[''.join(v)]=[nextstr,'L']
		v[coor],v[coor+1]=v[coor+1],v[coor]
	if 0<y:
		v[coor],v[coor-X]=v[coor-X],v[coor]
		if ''.join(v) not in m:
			m[''.join(v)]=[coor-X,depth+1]
			q.append(v[:])
			prev[''.join(v)]=[nextstr,'D']
		v[coor],v[coor-X]=v[coor-X],v[coor]
	if y<Y-1:
		v[coor],v[coor+X]=v[coor+X],v[coor]
		if ''.join(v) not in m:
			m[''.join(v)]=[coor+X,depth+1]
			q.append(v[:])
			prev[''.join(v)]=[nextstr,'U']
		v[coor],v[coor+X]=v[coor+X],v[coor]

try:
	while True:
		v=raw_input().split()
		print(m[''.join(v)][1])
except EOFError:
	pass