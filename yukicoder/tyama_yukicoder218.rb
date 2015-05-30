#!/usr/bin/ruby
a,b,c=$<.map &:to_i
puts (a+b-1)/b*2/3*c>=a ?:YES: :NO