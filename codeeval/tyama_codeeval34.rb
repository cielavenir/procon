#!/usr/bin/ruby
while s=gets
	a=s.split(/;/)
	b=a[1].to_i
	c=a[0].split(/,/).map{|e|e.to_i}
	d=0
	c.each{|e|
		break if e>=(b+1)/2
		if c.include?(b-e)
			print ';' if d>0
			print e.to_s+','+(b-e).to_s
			d+=1
		end
	}
	puts d==0?"NULL":""
end