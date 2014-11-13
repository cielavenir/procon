#!/usr/bin/ruby
n=gets.chomp
puts n.to_i%3==0||n.index('3') ? :Yes : :No