#!/usr/bin/ruby
popcnt=->n{n==0?0:popcnt[n/2]+n%2}
N=gets.to_i
F=N.times.map{gets.tr(' ','').to_i(2)}
P=N.times.map{gets.split.map &:to_i}
r=-Float::INFINITY
1.upto(1023){|i|
	c=0
	N.times{|j|c+=P[j][popcnt[i&F[j]]]}
	r=[r,c].max
}
p r
