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
e=[0]*(N*2+1)
f=[0]*(N*2+1)
while True:
	for i in range(N*2): e[i+1]=e[i]+e0[i]
	#e=reduce(lambda s,_: (s.append(s[-1:][0]+_),s)[1],e0,[0])
	#数学の座標系のように左下をA、右上をBとすると、eの各インデックスiにおいて、x座標がi-e[i]、y座標がe[i]となる。
	while True:
		for i in range(N*2): f[i+1]=f[i]+f0[i]
		#f=reduce(lambda s,_: (s.append(s[-1:][0]+_),s)[1],f0,[0])
		if all(e[i]!=f[i] or e[i+1]!=f[i+1] for i in range(N*2)): r+=1
		#i番目の座標とi+1番目の座標が等しければ、「道に重複がある」とみなせる。
		if not next_permutation(f0): break
	if not next_permutation(e0): break
print(r) # 100360
