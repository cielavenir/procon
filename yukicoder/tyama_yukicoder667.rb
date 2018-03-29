#!/usr/bin/ruby
s=gets.chomp
a,b=s.count(?o),s.count(?x)
s.size.times{|i|
	p a*100.0/(a+b)
	s[i]==?o ? a-=1 : b-=1
}
