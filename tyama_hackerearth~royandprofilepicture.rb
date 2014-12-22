#!/usr/bin/ruby
l=gets.to_i
gets.to_i.times{
	a=gets.split.map(&:to_i)
	puts a.any?{|e|e<l} ? 'UPLOAD ANOTHER' : a[0]!=a[1] ? 'CROP IT' : 'ACCEPTED'
}