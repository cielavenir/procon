#!/usr/bin/ruby
puts$<.map{|l|
	a,b=l.split'|'
	b.split.map{|e|a[e.to_i-1,1]}*''
}