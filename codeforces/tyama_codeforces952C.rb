#!/usr/bin/ruby
n,*a=$<.read.split.map &:to_i
puts a.each_cons(2).all?{|x,y|(x-y).abs<2} ? :YES : :NO
