#!/usr/bin/ruby
p,n=gets.split.map(&:to_i)
h={}
n.times{|i|
	x=gets.to_i%p
	if h[x]
		p i+1
		exit
	end
	h[x]=1
}
puts -1