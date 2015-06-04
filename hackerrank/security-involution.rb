#!/usr/bin/ruby
N=gets.to_i
a=gets.split.map(&:to_i)
b=N.times.map{|i|a[a[i]-1]}
puts [*1..N]==b ? :YES : :NO