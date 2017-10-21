#!/usr/bin/ruby
N,K=gets.split.map &:to_i
A=N.times.map{gets.split.map &:to_i}.sort
x,y=A.transpose
Y=y.sort
r=(x[-1]-x[0])*(Y[-1]-Y[0])
N.times{|i|(i+1...N).each{|j|N.times{|k|(k+1...N).each{|l|
	ly=Y[k];ry=Y[l];q=(x[j]-x[i])*(ry-ly)
	r=q if r>q&&j-i+1>=K&&(i..j).count{|z|
		ly<=y[z]&&y[z]<=ry
	}>=K
}}}}
p r
