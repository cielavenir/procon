#!/usr/bin/ruby
N,M,X=gets.split.map &:to_i
puts N-M+3<=X ? :YES : :NO
