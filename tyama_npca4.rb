#!/usr/bin/ruby
n,m=gets.split.map(&:to_i)
p n.times.map{m.times.map{gets.to_i}}.transpose.reduce(0){|s,e|s+=e.max}