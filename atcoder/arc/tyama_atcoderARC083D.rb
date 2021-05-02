#!/usr/bin/ruby
r=0
(n,),*m=$<.map{|e|e.split.map &:to_i}
n.times{|i|(i+1...n).each{|j|z=m[i][j]
	(0...n).all?{|k|(0<d=z-m[i][k]-m[k][j])&&(p -1;exit);i==k||j==k||d<0}&&r+=z
}}
p r
