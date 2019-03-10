#!/usr/bin/ruby
s=gets
s.size.downto(0){|i|s[i,2]=='WA'&&s[i,2]='AC'}
puts s
