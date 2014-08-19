#!/usr/bin/ruby
n=gets.to_i
m=$<.map{|e|e.split.map(&:to_i)}
1.step(n-1){|i|m[i][0]+=m[i-1][0]}
1.step(n-1){|j|m[0][j]+=m[0][j-1]}
1.step(n-1){|i|1.step(n-1){|j|
	m[i][j]+=[m[i-1][j],m[i][j-1]].min
}}
p m[n-1][n-1]