#!/usr/bin/ruby
a,b,n=gets.split.map &:to_i
p [a,b,a^b][n%3]