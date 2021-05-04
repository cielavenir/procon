#!/usr/bin/ruby
x,y,z=gets.split.map &:to_i
puts x*y*z%3>0?:No: :Yes
