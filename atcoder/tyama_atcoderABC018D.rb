#!/usr/bin/ruby
N,M,P,Q,R=gets.split.map &:to_i
Z=(0..N).map{[0]*-~M}
R.times{x,y,z=gets.split.map &:to_i;Z[x][y]=z}
p [*1..N].combination(P).map{|f|
	s=[0]*-~M
	f.map{|e|0.upto(M){|i|s[i]+=Z[e][i]}}
	s.sort[-Q,Q].reduce :+
}.max
