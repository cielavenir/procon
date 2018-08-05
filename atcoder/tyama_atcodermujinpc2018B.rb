#!/usr/bin/ruby
n=gets.to_i
puts n==0 || gets.chomp.chars.any?{|c|
n+=(c=='+' ? 1 : -1)
n==0
} ? :Yes : :No
