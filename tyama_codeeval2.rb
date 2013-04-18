#!/usr/bin/ruby
n=gets.to_i
a=ARGF.map(&:chomp)
puts a.sort{|a,b|-(a.length<=>b.length)}[0,n]