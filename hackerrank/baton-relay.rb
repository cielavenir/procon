#!/usr/bin/ruby
n,m=gets.split.map(&:to_i)
r=0
n.times{_,b=gets.split.map(&:to_f);r+=m/b}
p r