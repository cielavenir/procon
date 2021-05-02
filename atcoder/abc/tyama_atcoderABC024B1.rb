#!/usr/bin/ruby
N,T=gets.split.map(&:to_i)
a=r=0
$<.each{|_|
	n=_.to_i
	r+=n-a if n<a
	r+=T
	a=n+T
}
p r