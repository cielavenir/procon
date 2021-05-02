#!/usr/bin/ruby
c=0
r=1
n=gets.to_i
(2*n).times.map{|i|[gets.to_i,i<n]}.sort.each{|k,v|
	if !v
		r*=c if c>0
		c-=1
	else
		r*=-c if c<0
		c+=1
	end
	r%=10**9+7
}
p r
