#!/usr/bin/ruby
A,B,C=$<.map &:to_i
puts Rational A*B*C,[C-A,C+A].product([C-B,C+B]).map{|x,y|(x*B).gcd y*A}.max