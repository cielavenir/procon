#!/usr/bin/ruby
def f(k,c,x,a,d)
	if k==0
		c
	elsif d==a.size
		Float::INFINITY
	elsif x<a[d]
		f(k-1,c,a[d],a,d+1)
	else
		[f(k,c,x,a,d+1),f(k-1,c+x+1-a[d],x+1,a,d+1)].min
	end
end
n,k,*a=`dd`.split.map &:to_i
p f(k-1,0,a[0],a,1)
