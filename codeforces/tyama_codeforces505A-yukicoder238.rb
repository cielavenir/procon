#!/usr/bin/env ruby
S=gets.chomp
puts (I=(0...L=S.size).find{|i|S[i]!=S[L-1-i]})?[S[0,I]+S[L-1-I]+S[I,L],S[0,L-I]+S[I]+S[L-I,L]].find{|e|e==e.reverse}||:NA:S[0,L/2]+S[L/2]+S[L/2,L]