#!/usr/bin/ruby
S=gets.chomp;L=S.size;r=0
L.times{|i|r+=L-1+(S[i]==?U?i:L-i-1)}
p r
