#!/usr/bin/ruby
gets.to_i.times{
	s=gets.chomp
	r=0
	loop{
		break if not s.sub!(/^.*?(tokyo|kyoto)/,'')
		r+=1
	}
	p r
}