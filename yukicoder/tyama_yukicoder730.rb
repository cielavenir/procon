#!/usr/bin/ruby
s=gets.chomp
puts s.chars.uniq.size==s.size ? :YES : :NO
