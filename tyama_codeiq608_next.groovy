#!/usr/bin/groovy
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
e=[0]*(N*2+1)
f=[0]*(N*2+1)
while(true){
	(N*2).times{e[it+1]=e[it]+e0[it]}
	//数学の座標系のように左下をA、右上をBとすると、eの各インデックスiにおいて、x座標がi-e[i]、y座標がe[i]となる。
	while(true){
		x=!(0..N*2-1).any{
			f[it+1]=f[it]+f0[it]
			//i番目の座標とi+1番目の座標が等しければ、「道に重複がある」とみなせる。
			e[it]==f[it] && e[it+1]==f[it+1]
		}
		if(x)r++
		if(!next_permutation(f0))break;
	}
	if(!next_permutation(e0))break
}
println r // 100360