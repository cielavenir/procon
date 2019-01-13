#!/usr/bin/ruby
t,b,*a=`dd`.split.map &:to_i
a.each{|e|
	e<1&&(puts ?0;next)
	s=''
	while e!=0
		s<<(e%-b).to_s
		e/=-b
		e=-e
	end
	puts s.reverse
}
