#!/usr/bin/ruby
n,k,x=gets.split.map(&:to_i)
m=n.times.map{gets.split.map(&:to_i)}
k.times{
	r=[x]
	r<<x=(1103515245*x+12345)%2**31
	x=(1103515245*x+12345)%2**31
	m<<r
}
p m.combination(2).map{|x,y|(x[0]-y[0]).abs+(x[1]-y[1]).abs}.min
