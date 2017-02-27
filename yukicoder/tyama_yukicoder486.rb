#!/usr/bin/ruby
gets.chomp.bytes.chunk{|e|e}.each{|k,v|
	if v.size>2
		puts k==79 ? :East : :West
		exit
	end
}
puts :NA
