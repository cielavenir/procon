#!/usr/bin/ruby
$<.each{|l|
	a,b=l.split'|'
	puts b.split.map{|e|a[e.to_i-1,1]}*''
}