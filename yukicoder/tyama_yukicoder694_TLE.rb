#!/usr/bin/ruby
W=[0]*10**6
def bit(a,n)
	r=0
	i=n-1
	while i>=0
		idx=a[i];(r+=W[idx];idx&=idx-1)while idx>0
		idx=a[i];(W[idx]+=1;idx+=idx&-idx)while idx<=n
		i-=1
	end
	r
end
n,*a=$<.map(&:to_i)
z=(1..n).sort{|i,j|a[i-1]!=a[j-1] ? a[i-1]<=>a[j-1] : i<=>j}
x=bit(z,z.size)
b=a.sort
n.times{|i|
	p x
	x-=((0...n).bsearch{|j|a[i]<=b[j]}||n)-n+((0...n).bsearch{|j|a[i]<b[j]}||n)
}
