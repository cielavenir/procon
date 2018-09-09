#!/usr/bin/ruby
gets.to_i.times{gets;s=gets.chomp
	puts [s.bytes,s.bytes.reverse].transpose.all?{|x,y|[-2,0,2].include?(x-y)} ? :YES : :NO
}
