#!/usr/bin/python
#coding:utf-8
import sys
if sys.version_info[0]<3:
	input=raw_input
	range=xrange

def popcnt(n):
	r=0
	while n>0:
		r+=n%2
		n//=2
	return r

def lightsout(x,y):
	a=[[0,0] for _ in range(x*y)]

	#create problem
	for i in range(x):
		for j in range(y):
			a[i+j*x][0]=1<<(i+j*x)
			a[i+j*x][1]= 0 +\
				(1<<(i+j*x)) |\
				(1<<(i-1+j*x) if i>0   else 0) |\
				(1<<(i+1+j*x) if i<x-1 else 0) |\
				(1<<(i+(j-1)*x) if j>0   else 0) |\
				(1<<(i+(j+1)*x) if j<y-1 else 0) |\
				(1<<(i-1+(j-1)*x) if i>0   and j>0   else 0) |\
				(1<<(i+1+(j-1)*x) if i<x-1 and j>0   else 0) |\
				(1<<(i-1+(j+1)*x) if i>0   and j<y-1 else 0) |\
				(1<<(i+1+(j+1)*x) if i<x-1 and j<y-1 else 0) |\
				0

	#solve
	badbits=0
	for i in range(x*y):
		if (a[i][1]&(1<<i))==0:
			for j in range(i+1,x*y):
				if (a[j][1]&(1<<i))!=0:
					a[i],a[j]=a[j],a[i]
					break
			else:
				badbits|=1<<i
				continue
		for j in range(x*y):
			if i==j: continue
			if (a[j][1]&(1<<i))!=0:
				a[j][0]^=a[i][0]
				a[j][1]^=a[i][1]

	k=x*y-popcnt(badbits)
	#STDERR.puts "quiet pattern=%d"%[x*y-k]

	#0解(quiet pattern)の集合tを用意する
	tmsk=0
	t=[]
	a_ok=[]
	for i in range(x*y):
		if ((badbits>>i)&1):
			t.append(a[i][0])
		else:
			a_ok.append((i,a[i][0]))
			tmsk|=1<<i
	print(t)

	#入力・解の存在判定
	input_=0
	for j in range(y):
		a=list(map(int,input().split()))
		for i in range(x):
			input_|=a[i]<<j*x+i
	if any(popcnt(e&input_)%2 for e in t):
		return -1

	tlst=[0]*(1<<(x*y-k))
	for l in range(1<<(x*y-k)):
		r=0
		for j in range(x*y-k):
			if (l&(1<<j)):
				r^=t[j]
		tlst[l]=r

	r0=1<<29
	c0=0
	for j in a_ok:
		if (input_&(1<<j[0])):
			c0^=j[1]
	#0解の重ね合わせをすべて試す
	for l in range(1<<(x*y-k)):
		r1=c0
		r1^=tlst[l]
		r0=min(r0,popcnt(r1))
	return r0

try:
	while True:
		m,n=map(int,input().split())
		r=lightsout(n,m)
		print('Impossible' if r<0 else r)
except EOFError:
	pass
