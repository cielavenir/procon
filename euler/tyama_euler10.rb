#!/usr/bin/ruby
require 'prime'
pr=Prime.each(2000000).to_a
gets.to_i.times{
	n=gets.to_i
	p pr.take_while{|e|e<=n}.reduce(:+)
}
__END__
1
2000000