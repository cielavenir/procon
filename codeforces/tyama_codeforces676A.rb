#!/usr/bin/ruby
n=gets.to_i
a,b=gets.split.map(&:to_i).each_with_index.select{|e,i|e==1||e==n}.map(&:last)
p [n-1-a,n-1-b,a,b].max