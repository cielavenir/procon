#!/usr/bin/ruby
sum_1_11=66
y,m=gets.split.map(&:to_i)
#2013 1を66月目としてm月目
m=(m-1)+12*(y-2012)+sum_1_11
#2次不等式x(x+1)/2<=m <=> x^2+x-2m<=0を解く
x=((-1+Math.sqrt(1+8*m))/2).to_i
y=m-x*(x+1)/2
puts [x+2001,y+1]*' '