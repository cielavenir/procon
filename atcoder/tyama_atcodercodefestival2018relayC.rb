#!/usr/bin/ruby
n,h,*a=`dd`.split.map &:to_i
m=[1]+[0]*2**n
(2**n).times{|q|
	s=0;n.times{|i|q[i]<1&&(h>=s+=a[i])&&m[q|1<<i]+=m[q]}
}
p m[-2]
