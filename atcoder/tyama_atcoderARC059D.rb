#!/usr/bin/ruby
s=gets.chomp
(0...s.size).each{|i|
	[1,2].each{|j|
		if s[i]==s[i+j]
			puts '%d %d'%[i+1,i+j+1]
			exit
		end
	}
}
puts '-1 -1'