#!/usr/bin/ruby
gets.to_i.times{
	a,b,x=gets.split.map(&:to_i)
	n=a==1 ? 1 : b>=0 ? a**b : 0
	p [n/x*x,n/x*x+x].min_by{|e|(n-e).abs}
}