#!/usr/bin/ruby
gets
a=gets.split.map(&:to_i)
puts a.size%2==1 ? :error : a.each_slice(2).map{|x,y|y-x}.reduce(:+)