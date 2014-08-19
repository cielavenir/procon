#!/usr/bin/ruby
while s=gets
	s.chomp!
	if s.size==0 then next end
	puts s.split.reverse*' '
end