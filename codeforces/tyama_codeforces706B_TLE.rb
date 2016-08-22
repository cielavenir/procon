#!/usr/bin/ruby
n=gets.to_i
a=gets.split.map(&:to_i).sort
gets.to_i.times{
	e=gets.to_i
	z=(0...n).bsearch{|i|e<a[i]}||n
	p z
}