#!/usr/bin/ruby
gets
h=Hash.new(0)
gets.split.each{|e|h[e.to_i]+=1}
p h.count{|k,v|v==1}