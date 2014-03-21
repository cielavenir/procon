#!/usr/bin/ruby
s=gets.chomp
i=s.size-1
while i>0
	break if s[0,i]==s[-i,i]
	i-=1
end
puts s+s[i..-1]