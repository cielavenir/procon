#!/usr/bin/ruby
a=gets.split.map &:to_i
s=a.reduce :+
puts s.odd? || a.combination(3).none?{|b|b.reduce(:+)==s/2} ? :NO : :YES
