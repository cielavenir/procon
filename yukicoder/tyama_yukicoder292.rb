#!/usr/bin/ruby
if RUBY_VERSION<'2.2'
	module Kernel
		def itself
			self
		end
	end
end
s,*x=gets.split.zip([:itself.to_proc,:to_i.to_proc,:to_i.to_proc]).map{|x,y|y.call(x)}
x.uniq.sort.reverse.each{|i|s=s[0,i]+s[i+1..-1]}
puts s