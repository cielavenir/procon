#!/usr/bin/ruby
N=gets.to_i
N<3&&(p -1;exit)
a=[*1...N]
N.times{|i|
	puts a.map{|e|e+(i<e ? 1 : 0)}*' '
	a.rotate!(-1)
}
