#!/usr/bin/ruby
n,p=gets.split.map(&:to_i)
m=r=0
$<.map(&:chomp).reverse.each{|e|
	m+=1 if e.end_with?('plus')
	r+=m*p/2
	m*=2
}
p r