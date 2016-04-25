#!/usr/bin/ruby
r=x=0
gets.to_i.to_s(2).chars{|c|
	if c=='1'
		x+=1
	else
		x=0
	end
	r=[r,x].max
}
p r