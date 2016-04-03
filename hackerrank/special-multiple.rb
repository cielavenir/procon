#!/usr/bin/ruby
f=->n{n.to_s(2).to_i*9}
gets.to_i.times{
	n=gets.to_i
	r=(1..1/0.0).find{|i|f.(i)%n==0}
	p f[r]
}