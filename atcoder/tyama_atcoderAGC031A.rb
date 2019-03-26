#!/usr/bin/ruby
unless Enumerable.method_defined? :tally
	module Enumerable
		def tally
			group_by(&:itself).map{|k,v|[k,v.size]}.to_h
		end
	end
end

gets;p gets.chomp.each_char.tally.map{|k,v|v+1}.reduce(:*)%(10**9+7)-1
