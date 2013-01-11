#!/usr/bin/ruby
require 'prime'
p=0;q=1;
3.step(1/0.0,2){|i|
	i=i.to_i
	(i*i).step(i*i-3*i+3,-i+1){|j|
		j.prime? ? p+=1:q+=1
	}
	if p*9<q then p i;exit end
}