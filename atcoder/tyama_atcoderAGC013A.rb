#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i
c=d=nil
r=0
a.each{|e|
	if !c||(e-d)*(d-c)<0
		c=d=e
		r+=1
	else
		d=e
	end
}
p r
