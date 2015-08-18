#!/usr/bin/ruby
N,A,B=gets.split.map(&:to_i)
Z=N.times.map{gets.to_f}
E=Z.reduce(:+)/Z.size
D=Z.minmax.reverse.reduce(:-)
if D==0&&(A!=E||B!=0)
	p -1
else
	puts [B/D,A-E*B/D]*' '
end