#!/usr/bin/ruby
l=gets.to_i
h=gets.to_i
s=gets.chomp.upcase.tr('^A-Z','?')
table=[*'A'..'Z','?']
a=27.times.map{[]}
h.times{
	line=gets.chomp
	line.chars.each_slice(l).each_with_index{|e,i|a[i]<<e*''}
}
puts s.chars.map{|e|
	a[table.index(e)]
}.transpose.map(&:join)