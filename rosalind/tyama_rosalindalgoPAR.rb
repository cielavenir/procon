#!/usr/bin/ruby
gets
a=gets.split.map(&:to_i)
x=a.shift
h,l=a.partition{|e|e>x}
puts (l+[x]+h)*' '