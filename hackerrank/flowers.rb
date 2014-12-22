#!/usr/bin/ruby
n,k=gets.split.map(&:to_i)
p gets.split.map(&:to_i).sort.reverse.each_slice(k).with_index(1).map{|e,i|e.reduce(:+)*i}.reduce(:+)