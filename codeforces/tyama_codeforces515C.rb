#!/usr/bin/env ruby
require 'prime'
h=Hash.new(0)
gets
gets.chomp.chars{|c|(2..c.to_i).each{|e|e.prime_division.each{|n,p|h[n]+=p}}}
h[7].times{
	h[5]-=1
	h[3]-=2
	h[2]-=4
	print 7
}
h[5].times{
	h[3]-=1
	h[2]-=3
	print 5
}
h[3].times{
	h[2]-=1
	print 3
}
h[2].times{
	print 2
}