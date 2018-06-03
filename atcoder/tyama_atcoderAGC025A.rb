#!/usr/bin/ruby
n=gets.chomp.chars.map(&:to_i).reduce :+;p n<2?10:n
