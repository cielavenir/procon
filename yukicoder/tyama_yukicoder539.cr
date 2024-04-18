#!/usr/bin/env crystal
require "big"
gets.to_s.to_i.times{
	s=gets.to_s.chomp
	endidx=s.rindex(/\d/)
	(puts s;next) if !endidx
	endidx+=1
	beginidx=(s[0,endidx].rindex(/[^\d]/)||-1)+1
	q=s[beginidx...endidx]
	if q[0]=='0'
		q="%0*d" % [q.size,BigInt.new(q)+1]
	else
		q=(BigInt.new(q)+1).to_s
	end
	puts s[0,beginidx]+q+s[endidx..-1]
}
