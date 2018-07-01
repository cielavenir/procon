#!/usr/bin/ruby
S,T,D,*w=$<.read.split.map &:to_i
v=[0]
D.times{|i|v[i+1]=v[i]+w[i]}
m=v.min;z=-v[-1]
if i=(0..D).find{|i|S+v[i]<=T}
	p i
elsif z<=0
	p -1
else
	x=z>0?(S+m-T+z-1)/z:0
	p (0..D).find{|i|S-z*x+v[i]<=T}+x*D
end
