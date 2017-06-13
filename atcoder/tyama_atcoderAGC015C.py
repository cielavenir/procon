#!/usr/bin/python
f=lambda s,h,w,a,q:s[h+1].__setitem__(w+1,s[h+1][w]+s[h][w+1]-s[h][w]+a[h][w]*q)
g=lambda s,y1,x1,y2,x2:s[y2][x2]-s[y2][x1-1]-s[y1-1][x2]+s[y1-1][x1-1]
H,W,N=map(int,raw_input().split())
a=[map(int,raw_input())for _ in[0]*H]
s,s1,s2=[[[0]*(W+1)for _ in[0]*-~H]for _ in[0]*3]
for h in range(H):
	for w in range(W):
		f(s,h,w,a,1)
		f(s1,h,w,a,w+1<W and a[h][w+1])
		f(s2,h,w,a,h+1<H and a[h+1][w])
for _ in[0]*N:
	y1,x1,y2,x2=map(int,raw_input().split())
	print g(s,y1,x1,y2,x2)-g(s1,y1,x1,y2,x2-1)-g(s2,y1,x1,y2-1,x2)
