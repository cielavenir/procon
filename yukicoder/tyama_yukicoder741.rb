#!/usr/bin/ruby
n=gets.to_i;r=1
9.times{|i|r=r*(n+9-i)/(i+1)}
p r%(10**9+7)
