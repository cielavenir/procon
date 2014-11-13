#!/usr/bin/ruby
T=['','January','February','March','April','May','June','July','August','September','October','November','December']
s=gets.chomp
if s.to_i==0
	p T.index(s)||-1
else
	puts T[s.to_i]
end