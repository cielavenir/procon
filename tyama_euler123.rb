#!/usr/bin/ruby
require 'prime'
n=0
Prime.each{|e|
	n+=1
	if n%2==0 then next end
	if 2*n*e>10**10 then break end
}
p n