#!/usr/bin/ruby
(10**9).step(2*10**9,10){|i|
	s=(i**2).to_s
	if (0..9).map{|i|s[i*2]==((i+1)%10).to_s}.all? then p i;exit end
}