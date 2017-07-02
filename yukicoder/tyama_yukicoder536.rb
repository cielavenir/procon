#!/usr/bin/ruby
s=gets.chomp
if s[-2,2]=='ai'
	puts s[0...-2]+'AI'
else
	puts s+'-AI'
end
