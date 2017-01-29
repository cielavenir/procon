#!/usr/bin/ruby
h=Hash.new{|h,k|h[k]=[]}
n,m=gets.split.map(&:to_i)
m.times{
	a,b=gets.split.map(&:to_i)
	h[b]<<a
}
r=[0]*n
(n-1).downto(0){|i|
	next if r[i]==1
	h[i].each{|e|
		r[e]=1
	}
}
puts r.reverse.join.sub(/^0+/,'')
