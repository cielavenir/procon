#!/usr/bin/ruby
n=gets.to_i
a=gets.split.map(&:to_i)+[0]
r=c=0
n.times{|i|
	if a[i]<a[i+1]
		c+=1
	else
		r+=(c+1)*(c+2)/2
		c=0
	end
}
p r