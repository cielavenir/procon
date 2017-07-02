#!/usr/bin/ruby
s=gets
p (s.size/2-1).downto(0).find{|i|s[0,i]==s[i,i]}*2
#chomp, ~-s.size/2
