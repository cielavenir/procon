#!/usr/bin/ruby
require 'prime'
gets.to_i.times{
	n=gets.to_i
	s=1
	Prime.each{|e|
		break if s*e>=n
		s*=e
	}
	p s
}
__END__
1
1000000