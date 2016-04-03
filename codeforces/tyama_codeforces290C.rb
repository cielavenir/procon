#!/usr/bin/ruby
r=w=0.0
gets.to_i.times{|i|
	w+=1 if gets.to_i==1
	r=[r,w/-~i].max
}
p r