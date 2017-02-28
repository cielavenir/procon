#!/usr/bin/ruby
require 'prime'
n=gets.to_i
table=n.prime_division.flat_map{|n,p|[n]*p}
l=table.size
if l<2
	puts '%d %d'%[2+4*n,2+4*n]
	exit
end
m=n*2+1
(3**(l-2)*2).times{|i|
	table2=Array.new(3){|a|a=[]}
	table.each_with_index{|e,j|table2[i/3**j%3]<<e}
	edge=table2.map{|e|e.reduce(1,:*)}
	surface=edge[0]*edge[1]+edge[1]*edge[2]+edge[2]*edge[0]
	if surface<m
		m=surface
	end
}
puts '%d %d'%[2*m,2+4*n]
