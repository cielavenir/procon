#!/usr/bin/ruby
require 'rational'
gets.to_i.times{
	p 1.step(gets.to_i).reduce(&:lcm)
}
__END__
1
20