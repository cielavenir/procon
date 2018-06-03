#!/usr/bin/ruby
n,d,*x=`dd`.split.map &:to_i
r=0
n.times{|i|
	j=(0...n).bsearch{|_|x[i]+d<x[_]}||n
	r+=(j+~i-i+(0...n).bsearch{|_|x[i]-d<=x[_]})*(n-j)
}
p r
