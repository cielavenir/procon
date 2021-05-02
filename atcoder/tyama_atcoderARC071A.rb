#!/usr/bin/ruby
a,b,c=gets.split.map &:to_i
puts b-a==c-b ? :YES : :NO
