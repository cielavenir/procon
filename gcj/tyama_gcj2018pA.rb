#!/usr/bin/ruby
gets.to_i.times{
	a,b=gets.split.map &:to_i
	n=gets.to_i
	(a..b).bsearch{|i|
		puts i
		STDOUT.flush
		s=gets.chomp
		break if s=='CORRECT'
		s=='TOO_BIG'
	}
}
