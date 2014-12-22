#!/usr/bin/ruby
gets.to_i.times{
	n,m=gets.split.map(&:to_i)
	p n/m*m*(m-1)/2+n%m*(n%m+1)/2
}