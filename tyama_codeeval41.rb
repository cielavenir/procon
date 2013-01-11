#!/usr/bin/ruby
while s=gets
	s.chomp!
	if s.length==0 then next end
	a=s.split(/;/)
	b=a[0].to_i
	c=a[1].split(/,/).map{|e|e.to_i}
	x={}
	c.each{|e|
		if x.include?(e)
			puts e
			break
		end
		x[e]=1
	}
end