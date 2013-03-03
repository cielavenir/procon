#!/usr/bin/ruby
a,b,c=gets.split.map(&:to_i)
puts a<b&&b<c ? :Yes : :No