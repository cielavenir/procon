#!/usr/bin/ruby
n=gets.chomp
puts n.include?('3')||n.to_i%3==0 ? :YES : :NO