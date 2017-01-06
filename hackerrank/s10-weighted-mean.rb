#!/usr/bin/ruby
n=gets.to_i
a=gets.split.map(&:to_i)
b=gets.split.map(&:to_i)
puts '%.1f'%[a.zip(b).reduce(0){|s,(x,y)|s+x*y}.to_f/b.reduce(:+)]
