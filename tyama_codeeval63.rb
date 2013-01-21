#!/usr/bin/ruby
require 'prime'
a=Prime.each(10**5).to_a
while gets
	b=$_.split(',').map(&:to_i)
	p a.count{|e|b[0]<=e&&e<=b[1]}
end