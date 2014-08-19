#!/usr/bin/ruby
while s=gets
	a=s.chomp.split(/;/)
	puts (a[0].split(/,/)&a[1].split(/,/))*','
end