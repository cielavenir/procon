#!/usr/bin/env groovy
def next_permutation(a,n=a.size){
	if(n<0||a.size<n)return false
	if(n<a.size)a[0..a.size()-1]=a[0..n-1]+a[n..-1].reverse()
	k=(a.size-2..0).find{a[it]<a[it+1]}
	if(k==null){
		a[0..a.size()-1]=a.reverse()
		return false
	}
	l=(a.size()-1..k+1).find{a[k]<a[it]}
	z=a[k];a[k]=a[l];a[l]=z
	a[0..a.size()-1]=a[0..k]+a[k+1..-1].reverse()
	return true
}

N=6
e0=([0]*N+[1]*N).sort()
f0=([0]*N+[1]*N).sort()
//各Pは経路を表す。1が縦、0が横を表す。
r=0
i=0
while(true){
	while(true){
		flg=0
		zero1=0
		zero2=N
		one1=0
		one2=N
		(N*2).times{
			zero1 += e0[it]==0 ? 1 : 0
			one1  += e0[it]==1 ? 1 : 0
			zero2 -= f0[N*2-1-it]==0 ? 1 : 0
			one2  -= f0[N*2-1-it]==1 ? 1 : 0
			if(zero1==zero2)flg+=1
			if(one1==one2)flg+=1
		}
		if(flg>=2)r+=1
		if(!next_permutation(f0))break;
	}
	if(!next_permutation(e0))break
}
println r // 100360