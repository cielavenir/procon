#!/usr/bin/ruby
s=gets
n=gets.to_i
T=[*'A'..'Z']
S=T[0...n].join.downcase+T[n..-1].join
puts s.tr(S,S.swapcase)