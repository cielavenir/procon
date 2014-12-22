#!/usr/bin/python
#coding:utf-8
import sys
if sys.version_info[0]>=3: from functools import reduce

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
i=0
e=[0]*(N*2+1)
f=[0]*(N*2+1)
for _e in permutation(e0):
	for i in range(N*2): e[i+1]=e[i]+_e[i]
	#e=reduce(lambda s,_: (s.append(s[-1:][0]+_),s)[1],e0,[0])
	#数学の座標系のように左下をA、右上をBとすると、eの各インデックスiにおいて、x座標がi-e[i]、y座標がe[i]となる。
	for _f in permutation(f0):
		for i in range(N*2): f[i+1]=f[i]+_f[i]
		#f=reduce(lambda s,_: (s.append(s[-1:][0]+_),s)[1],f0,[0])
		if all(e[i]!=f[i] or e[i+1]!=f[i+1] for i in range(N*2)): r+=1
		#i番目の座標とi+1番目の座標が等しければ、「道に重複がある」とみなせる。
print(r) # 100360