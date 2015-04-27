#!/usr/bin/ruby
T='31415926535897932384626433833'
gets.to_i.times{
	a=gets.split
	puts "It's"+(a.size.times.all?{|i|a[i].size==T[i,1].to_i}?'':' not')+' a pi song.'
}