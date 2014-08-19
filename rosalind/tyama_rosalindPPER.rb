#!/usr/bin/ruby
a,b=gets.split.map(&:to_i)
p ((a-b+1)..a).reduce(1){|s,e|s*e%10**6}