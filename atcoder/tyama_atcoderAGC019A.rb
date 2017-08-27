#!/usr/bin/ruby
a,b,c,d,n=`dd`.split.map &:to_i;n*=4
h={1=>a,2=>b,4=>c,8=>d}
a=[0]
(1..8).each{|i|
	a[i]=Float::INFINITY
	h.each{|k,v|
		a[i]=[a[i],a[i-k]+v].min if i>=k
	}
}
d,r=n.divmod 8
p d*a[8]+a[r]
