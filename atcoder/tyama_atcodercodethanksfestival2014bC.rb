#!/usr/bin/ruby
gets
a=gets.split.map(&:to_i)
b=gets.split.map(&:to_i)
p b.size.times.count{|i|a[i]/2<b[i]}