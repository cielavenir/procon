#!/usr/bin/env ruby
#https://gist.github.com/mattsan/38a752dca30423902b0a

T={
	'A'=>{'R'=>'H','W'=>'I'},
	'B'=>{'R'=>'D','W'=>'G'},
	'C'=>{'R'=>'J','W'=>'A'},
	'D'=>{'R'=>'F','W'=>'I'},
	'E'=>{'R'=>'B','W'=>'C'},
	'F'=>{'R'=>'H','W'=>'A'},
	'G'=>{'R'=>'D','W'=>'E'},
	'H'=>{'R'=>'J','W'=>'C'},
	'I'=>{'R'=>'F','W'=>'G'},
	'J'=>{'R'=>'B','W'=>'E'},
}
if __FILE__==$0
	while gets
		puts $_.chomp.chars.reduce{|s,e|s<<T[s[-1]][e]}
		STDOUT.flush
	end
end