#!/usr/bin/ruby
IO.popen(ARGV[0],'r+'){|io|
	STDIN.map{|e|e.split.map(&:to_i)}.each{|n,i,e|
		io.puts i
		o=io.gets.chomp.to_i
		if o!=e
			puts n
		end
	}
}