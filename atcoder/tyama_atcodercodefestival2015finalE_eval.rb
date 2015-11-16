#!/usr/bin/ruby
s=gets.chomp
(-2..2).each{|i|
	n=i
	s.reverse.each_char{|c|
		n=-n if c=='-'
		n=n==0 ? 1 : 0 if c=='!'
	}
	p n
}