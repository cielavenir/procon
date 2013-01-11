#!/usr/bin/ruby
while s=gets
	a=s.chomp.split(/,/)
	puts(a[0].end_with?(a[1])?1:0)
end