#!/usr/bin/ruby
p 150
puts 'O'*150
149.times{|i|
	s='.'*150
	s[i,1]='O'
	puts s
}