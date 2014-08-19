#!/usr/bin/ruby
n,m=gets.split.map(&:to_i)
p gets.split.map(&:to_i).each_with_index.sort_by{|e,i|[(e+m-1)/m,i]}.last.last+1