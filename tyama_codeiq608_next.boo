#!/usr/bin/booi
import System
import System.Array

def next_permutation[of T(IComparable)](a as (T),n as int) as bool:
	if n<0 or len(a)<n: return false
	Reverse(a,n,len(a)-n)
	i=len(a)-2
	while i>=0:
		if a[i].CompareTo(a[i+1])<0: break
		i-=1
	if i<0:
		Reverse(a)
		return false
	k=i
	i=len(a)-1
	while i>=0:
		if a[k].CompareTo(a[i]): break
		i-=1
	l=i
	z=a[k];a[k]=a[l];a[l]=z
	Reverse(a,k+1,len(a)-(k+1))
	return true

N=6
e0 as (int)=array(int,N*2)
f0 as (int)=array(int,N*2)
for i in range(N): e0[N+i]=f0[N+i]=1
Sort(e0)
Sort(f0)

r=0
i=0
e as (int)=array(int,N*2+1)
f as (int)=array(int,N*2+1)
while true:
	for i in range(N*2): e[i+1]=e[i]+e0[i]
	#数学の座標系のように左下をA、右上をBとすると、eの各インデックスiにおいて、x座標がi-e[i]、y座標がe[i]となる。
	while true:
		x=1
		for i in range(N*2):
			f[i+1]=f[i]+f0[i]
			if e[i]==f[i] and e[i+1]==f[i+1]: x=0;break
		r+=x
		#i番目の座標とi+1番目の座標が等しければ、「道に重複がある」とみなせる。
		if not next_permutation[of int](f0,len(f0)): break
	if not next_permutation[of int](e0,len(e0)): break
print(r) # 100360
