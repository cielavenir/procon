#!/usr/bin/ruby
a,b,c,d,e,f=gets.split.map &:to_i
w=[];s=[]
(0..f).map{|i|(0..f).map{|j|
	x=(a*i+b*j)*100
	y=c*i+d*j
	w<<x if x<=f
	s<<y if y<=f
}}
g=[]
w.map{|i|s.map{|j|
	g<<[j*100.0/(i+j),i+j,j] if 0<i+j&&i+j<=f&&j<=i*e/100.0
}}
g=g.max
puts g[1..-1]*' '
