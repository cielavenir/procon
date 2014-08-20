#!/usr/bin/ruby
s="7 8 9 0\n 4 5 6\n  2 3\n   1\n"
gets
gets.split.each{|e|s=s.sub(e,'.')}
gets.split.each{|e|s=s.sub(e,'o')}
('0'..'9').each{|e|s=s.sub(e,'x')}
puts s