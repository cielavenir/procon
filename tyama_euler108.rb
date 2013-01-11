#!/usr/bin/ruby
require 'prime'
(2..1/0.0).each{|n|
	if (n.prime_division.reduce(1){|s,e|s*=e[1]*2+1}+1)/2 > 1000 then p n;exit end
}