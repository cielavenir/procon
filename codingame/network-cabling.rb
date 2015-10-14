#!/usr/bin/ruby
_,a=gets.to_i.times.map{
	gets.split.map(&:to_i)
}.transpose
lx=_.max-_.min
a.sort!
#n=(a.reduce(:+).to_f/a.size).round
n=(a[a.size/2]+a[~-a.size/2])/2
p lx+a.reduce(0){|s,e|s+(e-n).abs}