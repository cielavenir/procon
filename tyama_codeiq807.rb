#!/usr/bin/ruby
r=0
(1<<16).times{|i|
	j=('%016b'%i).reverse.to_i(2)
	s='%d%d%d%d'%[i>>8,i&0xff,j>>8,j&0xff]
	h=Hash.new(0)
	s.chars.each{|c|h[c]+=1}
	if ('0'..'9').all?{|e|h[e]==1}
		puts s
		r+=1
	end
}
p r # 8