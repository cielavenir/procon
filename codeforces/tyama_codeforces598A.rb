#!/usr/bin/ruby
def solve(n)
	i=1
	i*=2 while i*2<=n
	n*(n+1)/2-2*(i*2-1)
end
puts gets.to_i.times.map{solve(gets.to_i)}