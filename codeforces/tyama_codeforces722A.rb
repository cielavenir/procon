#!/usr/bin/ruby
n=gets.to_i
s=gets
s[3]=s[3]>'5'?'0':s[3]
if n==12
	if s[0]=='0'
		s[0]='1' if s[1]=='0'
	elsif s[0]=='1'
		s[1]='0' if s[1]>'2'
	else
		s[0]=s[1]=='0'?'1':'0'
	end
else
	if s[0]=='2'
		s[0]='0' if s[1]>'3'
	elsif s[0]>'2'
		s[0]='0'
	end
end
puts s
