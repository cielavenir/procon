#!/usr/bin/ruby
gets
a=gets.split.map &:to_i
gets
b=gets.split.map &:to_i
puts a.reduce(:*)==b.reduce(:*) ? :Yes : :No
