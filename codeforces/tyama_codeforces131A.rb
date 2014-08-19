#!/usr/bin/ruby
s=gets.chomp
puts s==s.upcase||s==s.capitalize.swapcase ? s.swapcase : s