#!/usr/bin/ruby
module Enumerable
	def min_by_map(&block)
		block.call(min_by(&block))
	end
end
a,b,c,*z=gets.split.map(&:to_i)
p [a,b,c].permutation.min_by_map{|x|x.zip(z).reduce(0){|s,(p,q)|s+(p-q).abs}}