#!/usr/bin/ruby
gets.to_i.times{
	s=gets.chomp
	p (s.size/2).times.reduce(0){|u,i|u+(s[i].ord-s[s.size-1-i].ord).abs}
}