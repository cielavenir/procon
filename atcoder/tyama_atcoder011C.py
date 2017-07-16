#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input

def diff1(t,s):
	r=0
	for i in range(len(t)):
		if t[i]!=s[i]: r+=1
		if r>1: return False
	return True

f,l=raw_input().split()
a=list({raw_input().rstrip() for i in range(int(raw_input()))})
if f==l:
	print(0)
	print(f)
	print(l)
	exit()
h={f:None}
q=[[f,0]]
while len(q)>0:
	x,y=q.pop(0)
	if diff1(x,l):
		q.append([l,y+1])
		h[l]=x
		break
	for e in a:
		if e not in h and diff1(x,e):
			q.append([e,y+1])
			h[e]=x
if len(q)==0:
	print(-1)
	exit()
a=[l]
x=l
while h[x]:
	a.append(h[x])
	x=h[x]
print(len(a)-2)
for e in reversed(a): print(e)
