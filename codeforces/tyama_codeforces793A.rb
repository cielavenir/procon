#!/usr/bin/ruby
n,k,*a=$<.read.split.map(&:to_i)
m=a.min
a=a.map{|e|e-m}
if a.all?{|e|e%k==0}
	p a.reduce(0){|s,e|s+e/k}
else
	p -1
end
