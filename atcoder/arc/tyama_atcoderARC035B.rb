#!/usr/bin/ruby
a=$<.drop(1).map(&:to_i).sort
p a.reduce([0,0]){|s,e|[s[0]+e,s[0]+s[1]]}.reduce(:+)
p a.chunk{|e|e}.reduce(1){|s,e|s*(1..e[1].size).reduce(:*)}%1000000007