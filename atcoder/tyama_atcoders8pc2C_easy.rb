#!/usr/bin/ruby
s=gets.chomp
d=gets.to_i
z=s.chars.map(&:to_i).reduce(:+)
p z<=d ? 1 : 0