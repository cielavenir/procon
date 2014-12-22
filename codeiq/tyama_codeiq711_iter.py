#!/usr/bin/python
#coding:utf-8

def find(cond,a):
	for e in a:
		if cond(e): return e
	return None
def permutation(x,n=None):
	if n==None: n=len(x)
	if n<0 or len(x)<n: return
	a=sorted(x)
	yield tuple(a[0:n])
	while True:
		a=a[0:n]+a[len(a)-1:n-1:-1]
		k=find(lambda i: a[i]<a[i+1], range(len(a)-2,-1,-1))
		if k==None: break
		l=find(lambda i: a[k]<a[i], range(len(a)-1,k,-1))
		a[k],a[l]=a[l],a[k]
		a=a[0:k+1]+a[len(a)-1:k:-1]
		yield tuple(a[0:n])

N=6
e0=[0]*N+[1]*N
f0=[0]*N+[1]*N
#各Pは経路を表す。1が縦、0が横を表す。
r=0
for _e in permutation(e0):
	for _f in permutation(f0):
		flg=0
		zero1=0
		zero2=N
		one1=0
		one2=N
		for i in range(N*2):
			zero1 += 1 if _e[i]==0 else 0
			one1  += 1 if _e[i]==1 else 0
			zero2 -= 1 if _f[N*2-1-i]==0 else 0
			one2  -= 1 if _f[N*2-1-i]==1 else 0
			if zero1==zero2: flg+=1
			if one1==one2: flg+=1
		if flg>=2: r+=1
print(r) # 527552