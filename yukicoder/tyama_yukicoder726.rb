#!/usr/bin/ruby
A=gets.split.map &:to_i
puts A.index(2)||A.reduce(0){|s,e|s^[e,2].max&1}<1 ? :Second : :First
