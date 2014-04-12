#!/usr/bin/ruby
a=$<.drop(1).map(&:to_i)
m=a.max
puts a.map{|e|['*']*e+[' ']*(m-e)}.transpose.map(&:join)