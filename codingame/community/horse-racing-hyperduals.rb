#!/usr/bin/ruby
n=gets.to_i
m=n.times.map{gets.split.map(&:to_i)}
p m.combination(2).map{|x,y|(x[0]-y[0]).abs+(x[1]-y[1]).abs}.min
