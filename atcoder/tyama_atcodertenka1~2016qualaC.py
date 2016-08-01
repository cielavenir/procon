#!/usr/bin/python
from __future__ import print_function
import sys
if sys.version_info[0]<3:input=raw_input

from heapq import*
g=[0]*676;d=[0]*26;n=int(input());r=[];q=[]
for i in range(n):
	a,b=input().split()
	for j in range(min(len(a),len(b))):
		if a[j]!=b[j]:y=ord(b[j])-97;x=ord(a[j])*26+y-2522;d[y]+=g[x]^1;g[x]=1;break
	else:
		if len(a)>len(b):print(-1);break
else:
	for i in range(26):
		if d[i]==0:heappush(q,i);d[i]=-1
	while q:
		n=heappop(q);r.append(n)
		for i in range(26):
			if g[n*26+i]:
				g[n*26+i]=0;d[i]-=1
				if d[i]==0:heappush(q,i);d[i]=-1
	print(-1 if sum(g)else''.join(chr(e+97)for e in r))