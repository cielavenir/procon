#!/usr/bin/ruby
n,d=gets.split.map(&:to_i)
a=gets.split.map(&:to_i).sort
m=gets.to_i
if m<a.size
	p a[0,m].reduce(:+)
else
	p a.reduce(:+)-d*(m-a.size)
end