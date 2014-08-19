#!/usr/bin/ruby
require 'prime'
h={}
#2.step(1000000){|i|h[i]=i.prime_division.reduce(1){|s,e|s*(e[0]**(e[1]+1)-1)/(e[0]-1)}-i}
#a=2.step(1000000).select{|i|x=h[i];x!=i&&h[x]==i}
a=[220, 284, 1184, 1210, 2620, 2924, 5020, 5564, 6232, 6368, 10744, 10856, 12285, 14595, 17296, 18416, 63020, 66928, 66992, 67095, 69615, 71145, 76084, 79750, 87633, 88730]
gets.to_i.times{
	n=gets.to_i
	p a.select{|e|e<n}.reduce(0,:+)
}
__END__
1
10000