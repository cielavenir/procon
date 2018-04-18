#!/usr/bin/ruby
require 'matrix'
n,x,y=gets.split.map &:to_i
a=n.times.map{
	c=gets.split.map &:to_i
	c[0]==1?Matrix[[1,0,c[1]],[0,1,0],[0,0,1]]:
	c[0]==2?Matrix[[1,0,0],[0,1,c[1]],[0,0,1]]:
	Matrix[[0,1,0],[-1,0,0],[0,0,1]]
}
(n-2).downto(0){|i|a[i]=a[i+1]*a[i]}
s=''.dup
n.times{|i|s<<(a[i]*Vector[x,y,1])[0..1]*' '+"\n"}
puts s
