#!/usr/bin/ruby
s=gets.chomp
n=s.scan(/[A-Z]/).size
puts n>s.size-n ? s.upcase : s.downcase