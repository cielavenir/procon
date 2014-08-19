#!/usr/bin/ruby
while s=gets
	a=s.split.reverse
	0.step(a.size-1,2){|i|
		if i>0 then print " " end
		print a[i]
	}
	puts
end