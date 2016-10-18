#!/usr/bin/ruby
a=gets.split.map(&:to_i)
m=a.max-1
p a.select{|e|e<m}.reduce(0){|s,e|s+m-e}
