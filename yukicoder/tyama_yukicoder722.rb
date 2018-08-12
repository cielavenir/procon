#!/usr/bin/ruby
a,b=gets.split
n=a.to_i*b.to_i
puts [a,b].all?{|e|e=~/^-?\d00+$/} ? n/10 : n.abs<1e8 ? n : :E
