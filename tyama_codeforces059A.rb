#!/usr/bin/ruby
s=gets.chomp
n=s.scan(/A-Z/).size
puts n>s.size ? s.upcase : s.downcase