#!/usr/bin/ruby
gets
s=gets.split.map(&:to_i)
r=0
gets.split.each{|e|
	n=e.to_i-1
	r+=s[n]
}
p r