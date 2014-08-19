#!/usr/bin/ruby
require 'prime'
9.upto(1/0.0){|i|
	if i%2==0 || i.prime? then next end
	1.step(i){|j|
		if 2*j**2 > i then p i;exit end
		if (i-2*j**2).prime? then break end
	}
}