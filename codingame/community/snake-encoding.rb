#!/usr/bin/ruby
n=gets.to_i
x=gets.to_i
m=n.times.map{gets.chomp.chars}
x.times{
	m=m.transpose
	c=m[0].shift
	1.upto(n-1){|i|
		m[i].send([:push,:unshift][i%2],c)
		c=m[i].send([:shift,:pop][i%2])
	}
	m[0].push(c)
	m=m.transpose
}
puts m.map(&:join)