#!/usr/bin/ruby
require 'prime'
STDOUT.sync=true
M=100
r=0
Prime.each(M/2){|e|
	p e
	if gets.chomp=='yes'
		r+=1
		if e*e<=M
			p e*e
			r+=1 if gets.chomp=='yes'
		end
	end
}
puts r>1 ? :composite : :prime