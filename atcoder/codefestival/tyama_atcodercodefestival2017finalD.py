#!/usr/bin/python
n=input()
A=sorted(([int(e) for e in raw_input().split()] for _ in range(n)),key=lambda (x,y):x+y)
H=[0]
for (x,y) in A:
	for i in range(len(H)-1,-1,-1):
		if x>=H[i]:
			if i==len(H)-1: H.append(1e9)
			H[i+1]=min(H[i]+y,H[i+1])
print len(H)-1
