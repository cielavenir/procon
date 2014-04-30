#!/usr/bin/python
#coding:utf-8
import sys
if sys.version_info[0]>=3: from functools import reduce

def find(cond,a):
	for e in a:
		if cond(e): return e
	return None
def next_permutation(a,n=None):
	if n==None: n=len(a)
	if n<0 or len(a)<n: return False
	a[0:len(a)]=a[0:n]+a[len(a)-1:n-1:-1]
	k=find(lambda i: a[i]<a[i+1], range(len(a)-2,-1,-1))
	if k==None:
		a.reverse()
		return False
	l=find(lambda i: a[k]<a[i], range(len(a)-1,k,-1))
	a[k],a[l]=a[l],a[k]
	a[0:len(a)]=a[0:k+1]+a[len(a)-1:k:-1]
	return True

N=6
e0=sorted([0]*N+[1]*N)
f0=sorted([0]*N+[1]*N)
#各Pは経路を表す。1が縦、0が横を表す。
r=0
i=0
while True:
	while True:
		flg=0
		zero1=0
		zero2=N
		one1=0
		one2=N
		for i in range(N*2):
			zero1 += 1 if e0[i]==0 else 0
			one1  += 1 if e0[i]==1 else 0
			zero2 -= 1 if f0[N*2-1-i]==0 else 0
			one2  -= 1 if f0[N*2-1-i]==1 else 0
			if zero1==zero2: flg+=1
			if one1==one2: flg+=1
		if flg>=2: r+=1
		if not next_permutation(f0): break
	if not next_permutation(e0): break
print(r) # 100360