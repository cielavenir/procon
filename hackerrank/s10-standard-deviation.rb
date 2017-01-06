#!/usr/bin/ruby
n=gets.to_i
a=gets.split.map(&:to_f)
puts '%.1f'%[Math.sqrt(a.map{|e|e**2}.reduce(:+)/n-(a.reduce(:+)/n)**2)]
