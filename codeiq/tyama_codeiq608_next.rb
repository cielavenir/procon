#!/usr/bin/ruby
def next_permutation(a,n=a.size)
	return if n<0||a.size<n
	a.replace(a[0,n]+a[n..-1].reverse)
	k=(a.size-2).downto(0).find{|i|a[i]<a[i+1]}
	if !k
		a.reverse!
		return false
	end
	l=(a.size-1).downto(k+1).find{|i|a[k]<a[i]}
	a[k],a[l]=a[l],a[k]
	a.replace(a[0,k+1]+a[k+1..-1].reverse)
	return true
end

N=6
#P=([0]*N+[1]*N).permutation2.to_a # N=5のとき、permutation.to_a.uniqの70倍速
e0=([0]*N+[1]*N).sort
f0=([0]*N+[1]*N).sort
#各Pは経路を表す。1が縦、0が横を表す。
r=0
i=0
e=[0]*(N*2+1)
f=[0]*(N*2+1)
begin
	(N*2).times{|i|e[i+1]=e[i]+e0[i]}
	#数学の座標系のように左下をA、右上をBとすると、eの各インデックスiにおいて、x座標がi-e[i]、y座標がe[i]となる。
	begin
		r+=1 if (N*2).times.none?{|i|
			f[i+1]=f[i]+f0[i]
			#i番目の座標とi+1番目の座標が等しければ、「道に重複がある」とみなせる。
			e[i]==f[i] && e[i+1]==f[i+1]
		}
	end while(next_permutation(f0))
end while(next_permutation(e0))
p r # 100360