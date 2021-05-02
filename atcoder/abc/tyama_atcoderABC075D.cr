#!/usr/bin/env crystal
n,m=gets.not_nil!.split.map(&.to_i64).to_a
a=(0...n).map{gets.not_nil!.split.map(&.to_i64).to_a}.sort
x,y=a.transpose
y0=y.sort
r=(x[-1]-x[0])*(y0[-1]-y0[0])
n.times{|i|(i+1...n).each{|j|n.times{|k|(k+1...n).each{|l|
	ly=y0[k];ry=y0[l];q=(x[j]-x[i])*(ry-ly)
	r>q&&m<=j-i+1&&m<=(i..j).count{|z|
		ly<=y[z]&&y[z]<=ry
	}&&(r=q)
}}}}
p r
