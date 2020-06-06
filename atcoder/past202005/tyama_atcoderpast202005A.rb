#!/usr/bin/ruby
s=gets.chomp
t=gets.chomp
puts s==t ? :same : s.upcase==t.upcase ? 'case-insensitive' : :different
