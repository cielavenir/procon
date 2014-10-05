#!/usr/bin/ruby
s=gets.chomp
result=[]
while s=~/@([a-z]+)/
	result<<$1
	s=s[$`.size+$1.size..-1]
end
puts result.uniq.sort