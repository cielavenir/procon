#!/usr/bin/ruby
h=Hash.new(0)
gets;gets.split.each{|e|h[e.to_i]+=1}
p h[0]>=1 ? ('5'*(h[5]/9*9)+'0'*h[0]).to_i : -1