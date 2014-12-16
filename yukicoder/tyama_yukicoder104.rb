#!/usr/bin/ruby
s=gets.chomp
r=1<<s.size
s.chars.each_with_index{|c,i|r+=1<<(s.size-i-1) if c=='R'}
p r