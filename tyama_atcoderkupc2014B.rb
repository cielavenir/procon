#!/usr/bin/ruby
require 'prime'
STDOUT.sync=true
M=1000
puts'! %d'%Prime.each(M).reduce(1){|s,e|
	s * e**((1..1/0.0).find{|i|
		s*e**i>M || (puts'? %d'%[e**i];gets.chomp=='N')
	}-1)
}