#!/usr/bin/ruby
n,d=gets.split.map &:to_i
t,k=gets.split.map &:to_i
k-=d
(n-1).times{
	t0,k0=gets.split.map &:to_i
	t,k=t0+[t,k-d].max,k0+[t-d,k].max
}
p [t,k].max
