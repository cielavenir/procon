#!/usr/bin/ruby
w,h,n,f=gets.split.map &:to_i
m=(h+1).times.map{|i|(w+1).times.map{|j|(i+j)*f}}
n.times{
	x,y,c=gets.split.map &:to_i
	h.downto(y){|i|w.downto(x){|j|
		m[i][j]=[m[i][j],m[i-y][j-x]+c].min
	}}
}
p m[h][w]
