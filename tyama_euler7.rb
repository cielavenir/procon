#!/usr/bin/ruby
require 'prime'
pr=Prime.take(10001)
gets.to_i.times{
	p pr[gets.to_i-1]
}
__END__
1
10001