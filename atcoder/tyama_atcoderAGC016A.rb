#!/usr/bin/ruby
s=gets.chomp
p ('a'..'z').map{|c|s.split(c).map(&:size).max.to_i}.min
