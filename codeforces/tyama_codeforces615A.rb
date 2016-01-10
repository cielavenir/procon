#!/usr/bin/ruby
n,m=gets.split.map(&:to_i)
a=[]
n.times{a|=gets.split.map(&:to_i)[1..-1]}
puts a.size==m ? :YES : :NO