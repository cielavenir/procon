#!/usr/bin/ruby
require 'date'
f=nil;while(a,b=gets.split.map &:to_i)!=[0,0]
	puts if f;f=1
	z=a.step(b).select{|i|Date.leap?(i)}
	z.size==0?puts('NA'):z.each{|e|p e}
end