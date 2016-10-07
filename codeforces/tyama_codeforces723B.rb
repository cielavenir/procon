#!/usr/bin/ruby
a=0;b=0
$<.read.split(')').each{|e|
	x,y=e.split('(')
	(x||'').scan(/[A-Za-z]+/).each{|f|a=[a,f.size].max}
	b+=(y||'').scan(/[A-Za-z]+/).size
}
puts [a,b]*' '
