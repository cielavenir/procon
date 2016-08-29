#!/usr/bin/ruby
n,s,*a=$<.read.split.map &:to_i
a.sort!
p n<2 ? 0 : [[0,-2],[1,-1]].map{|i,j|
	x,y=[[s-a[i],0].max,[a[j]-s,0].max].minmax
	x*2+y
}.min