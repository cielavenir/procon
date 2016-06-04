#!/usr/bin/ruby
require 'json'
a=JSON.parse(gets).sort
r=[]
last=a[0]
f=lambda{|x|
	if x-last>1
		r<<'%d-%d'%[last,x]
	else
		(last..x).each{|i|r<<i}
	end
}
a.each_cons(2){|x,y|
	if y-x>1
		f[x]
		last=y
	end
}
f[a[-1]] if a.size>1
puts r*','