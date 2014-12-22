#!/usr/bin/ruby
gets
a=gets.split.map(&:to_i)
i=a.each_with_index.max.last
a.rotate!(i+1)
p a.each_with_index.map{|e,i|e*(i+1)}.reduce(:+)