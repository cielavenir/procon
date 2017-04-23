#!/usr/bin/ruby
x,z=$<.map &:chomp
puts x.size.times.all?{|i|x[i]>=z[i]} ? z : -1
