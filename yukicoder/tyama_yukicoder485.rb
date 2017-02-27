#!/usr/bin/ruby
x,y=gets.split.map &:to_i
d,r=y.divmod x
puts r!=0?:NO:d
