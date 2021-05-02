#!/usr/bin/python
def checkio(first, second, k):
	lst={0}
	depth={(0,0):0}
	q=[(0,0)]
	while len(q)>0:
		x=q[0]
		q.pop(0)
		a=[
			('01',(first,x[1])),
			('02',(x[0],second)),
			('10',(0,x[1])),
			('20',(x[0],0)),
			('12',(x[0]-min(x[0],second-x[1]),x[1]+min(x[0],second-x[1]))),
			('21',(x[0]+min(first-x[0],x[1]),x[1]-min(first-x[0],x[1]))),
		]
		for e in a:
			if e[1] not in depth and depth[x]<k:
				lst.add(e[1][0])
				lst.add(e[1][1])
				depth[e[1]]=depth[x]+1
				q.append(e[1])
	return len(lst)

a=[int(e) for e in raw_input().split()]
print(checkio(*a))