#!/usr/bin/ruby
r=0
s=gets.chomp
s.size.times{|i|if s[i]=='Q'
(i+2...s.size).each{|j|if s[j]=='Q'
r+=(i+1...j).count{|k|s[k]=='A'}
end}
end}
p r
