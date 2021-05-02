#!/usr/bin/ruby
s=gets.chomp
puts s[(gets.to_i-1)%s.size,1]