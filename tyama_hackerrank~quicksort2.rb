#!/usr/bin/ruby
def partition(a)
	x=a.first
	b=a[1..-1].partition{|e|e<x}
	return [b[0].size,b[0]+[x]+b[1]]
end
def quicksort(a)
	return a if a.size<2
	n,a=partition(a)
	r=quicksort(a[0...n])+[a[n]]+quicksort(a[(n+1)..-1])
	puts r*' '
	r
end
gets;quicksort(gets.split.map(&:to_i))