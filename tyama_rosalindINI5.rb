#!/usr/bin/ruby
f=false
while gets
	puts $_ if f
	f=!f
end