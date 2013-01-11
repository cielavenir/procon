#!/usr/bin/ruby
require 'prime'
p=Prime::EratosthenesGenerator.new
h={};h[p.next]=1;h[p.next]=1;h[p.next]=1;h[p.next]=1
p Enumerator.new{|y|
	loop{
		e=p.next
		h[e]=1
		s=e.to_s
		y<<e if (s.length-1).times.all?{|i|h[s[0,i+1].to_i]&&h[s[i+1,s.length-i-1].to_i]}
	}
}.take(11).reduce(:+)