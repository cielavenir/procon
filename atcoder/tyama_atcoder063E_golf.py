#!/usr/bin/python
#import sys
#if sys.version_info[0]<3:input=raw_input

from heapq import*
R=range;I=lambda:map(int,input().split());n=int(input());g=[[]for _ in R(n+1)];z=[-1]*n;d=[1e9]*n+[0];q=[-1]*(n+1);r='';Q=[];heappush(Q,(0,-2,n))
for _ in R(n-1):a,b=I();a-=1;b-=1;g[a]+=[(1,a,b)];g[b]+=[(1,b,a)]
for _ in R(*I()):a,b=I();a-=1;g[n]+=[(b,n,a)];z[a]=b
while Q:
	e=heappop(Q)
	if q[e[2]]!=-1:continue
	q[e[2]]=e[1]
	for f in g[e[2]]:
		if d[f[2]]>e[0]+f[0]:d[f[2]]=e[0]+f[0];heappush(Q,(e[0]+f[0],f[1],f[2]))
for _ in g:
	if any(n!=e[1]and abs(d[e[1]]-d[e[2]])!=1 for e in _):r="No"
if any(~z[i]and z[i]!=d[i]for i in R(n)):r="No"
print(r or"Yes\n"+"\n".join(map(str,d[:n])))
