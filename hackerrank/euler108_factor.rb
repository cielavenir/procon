#!/usr/bin/ruby
FACTOR='gfactor'
gets
s=IO.popen(FACTOR,'r+b'){|io|
	io.write $<.read
	io.close_write
	io.read
}
s.each_line{|line|
	p (line.split[1..-1].group_by{|e|e}.reduce(1){|s,(k,v)|s*=v.size*2+1}+1)/2
}