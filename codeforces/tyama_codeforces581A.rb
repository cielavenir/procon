#!/usr/bin/ruby
a,b=gets.split.map(&:to_i)
puts '%d %d'%[s=[a,b].min,(a+b-s*2)/2]