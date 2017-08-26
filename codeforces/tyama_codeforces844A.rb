#!/usr/bin/ruby
s=gets.chomp
n=gets.to_i
puts s.size<n ? :impossible : [0,n-s.chars.uniq.size].max
