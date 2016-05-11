#!/usr/bin/ruby
n,q=gets.split.map(&:to_i)
a=[0]*n
q.times{
	l,r,t=gets.split.map(&:to_i)
	(l-1...r).each{|i|a[i]=t}
}
puts a