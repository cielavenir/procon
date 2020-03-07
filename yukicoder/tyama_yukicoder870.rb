#!/usr/bin/ruby
A=[[2,8],[3,9],[7,9]]
B=[[5,8],[4,8],[6,8]]
gets.to_i.times{
	a,b,c,d=gets.split.map &:to_i
	i=A.index([a,b])
	A[i]=[c,d] if i
}
puts A==B ? :YES : :NO
