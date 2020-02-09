#!/usr/bin/ruby
a,b=gets.split.map &:to_i
a*=10**50
r=(a/b).to_s.rjust(51,'0')
puts r[0...-50]+'.'+r[-50..-1]
