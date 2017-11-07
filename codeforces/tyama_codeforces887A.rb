#!/usr/bin/ruby
s=gets.chomp
i=s.index('1')
puts i&&s[i+1..-1].count('0')>=6 ? :YES : :NO
