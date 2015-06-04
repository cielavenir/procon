#!/usr/bin/ruby
s=gets.chomp.chars.to_a
if s.size==2 || s[0]==s[-1]
	puts 1
elsif s[0]==s[1]&&s[-2]==s[-1]
	puts 3
else
	puts 2
end