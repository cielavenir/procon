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
while true:
	while true:
		flg=0
		zero1=0
		zero2=N
		one1=0
		one2=N
		for i in range(N*2):
			if e0[i]==0: zero1+=1
			if e0[i]==1: one1+=1
			if f0[N*2-1-i]==0: zero2-=1
			if f0[N*2-1-i]==1: one2-=1
			if zero1==zero2: flg+=1
			if one1==one2: flg+=1
		if flg>=2: r+=1
		if not next_permutation[of int](f0,len(f0)): break
	if not next_permutation[of int](e0,len(e0)): break
print(r) # 100360