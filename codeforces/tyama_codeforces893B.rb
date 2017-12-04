#!/usr/bin/ruby
n=gets.to_i
r=1
k=2
loop{
	x=(2**k-1)*(2**~-k)
	break if n<x
	r=x if n%x==0
	k+=1
}
p r
