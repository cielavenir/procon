#!/usr/bin/ruby
h=2
w=gets.to_i
m=$<.map{|e|e.split.map &:to_i}
(1...h).each{|i|m[i][0]+=m[i-1][0]}
(1...w).each{|j|m[0][j]+=m[0][j-1]}
(1...h).each{|i|(1...w).each{|j|
	m[i][j]+=[m[i-1][j],m[i][j-1]].max
}}
p m[h-1][w-1]
