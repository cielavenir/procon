#!/usr/bin/ruby
#unfortunately, spoj factor cmd does not support GMP. So FACT2 cannot be solved.

IO.popen('factor','r'){|io|
	io.read
}.each_line{|line|
	h=Hash.new(0)
	line.split[1..-1].each{|e|h[e.to_i]+=1}
	puts h.map{|e|'%d^%d'%e}*' '
}
