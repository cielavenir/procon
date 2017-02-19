#!/usr/bin/ruby
s=gets.chomp.chars.uniq.join
puts s==[*'a'..'z'].join[0,s.size] ? :YES : :NO
