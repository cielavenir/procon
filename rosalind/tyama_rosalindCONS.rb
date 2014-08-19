#!/usr/bin/ruby
s=''
a=$<.map{|e|e.chomp.split''}.transpose.map{|e|
	b='ACGT'.chars.map{|e0|[e.count{|e1|e0==e1},e0]}
	s<<b.max[1]
	b
}.transpose
puts s
a.each{|e|
	puts e[0][1]+': '+e.map{|f|f[0]}*' '
}