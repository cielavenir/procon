#!/usr/bin/env ruby
H={'Q'=>9,'R'=>5,'B'=>3,'N'=>3,'P'=>1}
w=b=0
$<.read.each_char{|c|
	if H[c]
		w+=H[c]
	elsif H[c.upcase]
		b+=H[c.upcase]
	end
}
puts %w(White Draw Black)[(b<=>w)+1]