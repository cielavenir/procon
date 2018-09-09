#!/usr/bin/ruby
n=gets.to_i
puts n>gets.chomp.chars.uniq.size||n==1?:Yes: :No
