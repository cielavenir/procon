#!/usr/bin/ruby
a=(1..100).map{|e|e**2}
n=gets.to_i
p a.bsearch{|e|e>=n}-n