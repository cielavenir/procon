#!/usr/bin/ruby
s=gets.chomp
r=eval s
(1...s.size).each{|i|r=[r,eval(s[i..-1]+s[0,i])].max if s[i-1,2]=~/\d\d/}
p r