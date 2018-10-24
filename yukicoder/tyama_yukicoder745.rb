#!/usr/bin/ruby
a,b,c,d=gets.split.map &:to_i
r=0
k=-1
b.times{k+=1;r+=50*2**(k/100)}
a.times{k+=1;r+=100*2**(k/100)}
puts d<10 ? "Possible\n%d"%r : 'Impossible'
