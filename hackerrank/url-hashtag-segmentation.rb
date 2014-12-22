#!/usr/bin/ruby
words=File.readlines('words.txt').map(&:chomp).sort_by{|e|-e.size}
gets.to_i.times{
	s=gets.chomp
	if s[0,1]=='#'
		s=s[1..-1]
	else
		s=s.split('.')[-2]
	end
	orig=s[0..-1]
	r=[]
	while !s.empty?
		if s=~/^([\d\.]+)/
			r<<$1
			s=s[$1.size..-1]
		else
			a=words.find{|e|s.start_with?(e)}
			break if !a
			r<<a
			s=s[a.size..-1]
		end
	end
	puts s.empty? ? r*' ' : orig
}