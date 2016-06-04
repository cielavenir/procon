#!/usr/bin/ruby
gets
a=gets.split.map(&:to_i)
c=a.count(1)
p a[0,c].count(0)