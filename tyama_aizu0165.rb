#!/usr/bin/ruby
require 'prime'
P=Prime.each(10**6).to_a
while(n=gets.to_i)>0
	r=0
	n.times{
		p,m=gets.split.map(&:to_i)
		r+=P.find_all{|e|p-m<=e&&e<=p+m}.size
	}
	p r-n
end