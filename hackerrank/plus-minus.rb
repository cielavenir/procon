#!/usr/bin/ruby
N=gets.to_i
A=gets.split.map(&:to_i)
h=Hash.new(0)
A.each{|e|h[e<=>0]+=1}
p h[1].to_f/A.size
p h[-1].to_f/A.size
p h[0].to_f/A.size