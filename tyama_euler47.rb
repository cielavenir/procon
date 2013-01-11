#!/usr/bin/ruby
require 'prime'
c=0;i=1
while c<4
	i+=1
	c=i.prime_division.count==4?c+1:0
end
p i-3