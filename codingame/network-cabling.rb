#!/usr/bin/ruby
_,a=gets.to_i.times.map{
	gets.split.map(&:to_i)
}.transpose
lx=_.max-_.min
ave=(a.reduce(:+).to_f/a.size).round
p lx+a.reduce(0){|s,e|s+(e-ave).abs}