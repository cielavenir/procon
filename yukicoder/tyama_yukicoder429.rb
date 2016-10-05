#!/usr/bin/ruby
n,k,x=gets.split.map(&:to_i)
z=[*1..n]
(x-1).times{
	a,b=gets.split.map(&:to_i)
	z[a-1],z[b-1]=z[b-1],z[a-1]
}
gets
_=(k-x).times.map{a,b=gets.split.map(&:to_i)}.reverse
y=gets.split.map(&:to_i)
_.each{|a,b|
	y[a-1],y[b-1]=y[b-1],y[a-1]
}
puts (1..n).select{|i|y[i-1]!=z[i-1]}*' '
