#!/usr/bin/env ruby
n=gets.chomp.chars.map(&:to_i)
a=n.size.times.map{[0]*9}
n.each_with_index{|e,i|e.times{|j|a[i][j]=1}}
a=a.transpose.map{|e|e.join.to_i}.select{|e|e>0}
p a.size
puts a*' '