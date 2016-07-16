#!/usr/bin/ruby
n=gets.to_i
p gets.split.map(&:to_i).sort.each_slice(2).map{|x,y|x}.reduce(:+)