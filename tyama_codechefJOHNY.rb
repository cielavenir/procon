#!/usr/bin/ruby
gets.to_i.times{
	gets
	a=gets.split.map(&:to_i)
	n=a[gets.to_i-1]
	p a.sort.index(n)+1
}