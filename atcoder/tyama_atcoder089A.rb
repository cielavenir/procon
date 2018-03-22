#!/usr/bin/ruby
a,b=gets.split.map &:to_i
puts a*b%2>0?"Odd":"Even"
