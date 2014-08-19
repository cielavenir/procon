#!/usr/bin/ruby
require 'prime'
gets.to_i.times{
	p gets.to_i.prime_division.max[0]
}
__END__
1
600851475143