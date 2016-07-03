#!/usr/bin/ruby
gets
a=$<.map{|e|e.count('0')==0}
r=c=0
a.each{|e|
	if e
		c=0
	else
		r=[r,c+=1].max
	end
}
p r