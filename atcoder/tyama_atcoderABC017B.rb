#!/usr/bin/ruby
s=gets.chomp
puts s.scan(/(ch|o|k|u)/)*''==s ? :YES : :NO