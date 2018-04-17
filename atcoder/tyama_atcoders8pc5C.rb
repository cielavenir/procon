#!/usr/bin/ruby
gets.to_i.times{
	r=0
	s=gets.chomp
	mi,ma=s.chars.map{|c|
		r+=(c=='(' ? 1 : -1)
	}.minmax
	x=s.size/4
	puts -x<=mi&&ma<=x&&r==0 ? :Yes : :No
}
