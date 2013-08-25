#!/usr/bin/ruby
gets.to_i.times{
	n,k=gets.split.map(&:to_i)
	a=gets.split.map(&:to_i)
	b=gets.split.map(&:to_i)
	puts a.sort.zip(b.sort.reverse).all?{|e,f|e+f>=k} ? 'YES' : 'NO'
}