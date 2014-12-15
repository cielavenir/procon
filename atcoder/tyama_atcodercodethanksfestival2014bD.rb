#!/usr/bin/ruby
n,t=gets.split.map(&:to_i)
a=[0]*(t+1)
n.times{
	e=gets.to_i
	e.step(t,e){|i|a[i]+=1}
}
p a.max