#!/usr/bin/ruby
#a,b=gets.split.map(&:to_i);c,d=gets.split.map(&:to_i);p (a-c).abs+(b-d).abs+1
p$<.map{|e|e.split.map(&:to_i)}.transpose.map{|x,y|(x-y).abs}.reduce(:+)+1