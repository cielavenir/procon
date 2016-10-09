#!/usr/bin/ruby
W=%W(monday tuesday wednesday thursday friday saturday sunday)
n=(-W.index(gets.chomp)+W.index(gets.chomp))%7
puts [0,2,3].include?(n) ? :YES : :NO
