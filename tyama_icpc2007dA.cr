#!/usr/bin/env crystal
while true
	n=gets.not_nil!.to_i
	break if n==0
	s=n.times.map{gets.not_nil!.to_i}.to_a.sort[1..-2].inject{|s,e|s+e}
	p s/(n-2)
end