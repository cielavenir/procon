#!/usr/bin/ruby
r=k=0
n=gets.to_i
a=(n-1).times.map{gets.to_i}
(n-1).times{|i|
	b,c=gets.split.map &:to_i
	k+=c-b
	r+=k*a[i]
}
p r
