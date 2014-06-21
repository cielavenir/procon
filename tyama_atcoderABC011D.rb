#!/usr/bin/ruby
require 'rational'
def fact(n) (1..n).reduce(:*)||1 end

n,d=gets.split.map(&:to_i)
x,y=gets.split.map(&:to_i)
if x%d>0 || y%d>0
	puts '0'
	exit
end
x/=d
y/=d
x=-x if x<0
y=-y if y<0
n-=x+y
if n<0 || n%2>0
	puts '0'
	exit
end
z=0
#4 sided dice; times(+x)==x+times(-x), times(+y)==y+times(-y)
0.step(n,2){|i|z += fact(x+y+n) / (fact(i/2)*fact(i/2+x)*fact((n-i)/2)*fact((n-i)/2+y))}
p Rational(z,4**(x+y+n)).to_f