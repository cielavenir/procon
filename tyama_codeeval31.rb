#!/usr/bin/ruby
while s=gets
	a=s.chomp.split(',')
	r=a[0].rindex(a[1])
	puts(r ?r:-1)
end