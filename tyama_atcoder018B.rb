#!/usr/bin/ruby
p gets.to_i.times.map{gets.split.map(&:to_i)}.combination(3).count{|a,b,c|
	s=(b[0]-a[0])*(c[1]-a[1])-(b[1]-a[1])*(c[0]-a[0])
	s!=0 && s%2==0
}