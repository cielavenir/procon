#!/usr/bin/ruby
n=gets.to_i
a,b=[2,5].map{|e|(0..n).map{|i|e**i}}
p *a.product(b).map{|x,y|x*y}.sort
