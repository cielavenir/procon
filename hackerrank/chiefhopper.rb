#!/usr/bin/ruby
gets
a=gets.split.map(&:to_i)
r=0
(a.size-1).downto(0){|i|
	r=(a[i]+r)/2+(a[i]+r)%2
}
p r