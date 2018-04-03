#!/usr/bin/ruby
10.times{|i|
	p i
	STDOUT.flush
	s=gets.chomp
	if %q(worse terrible serious die even).any{|e|s.index e}
		puts :grumpy
		exit
	elsif %q(cool great think touch bad).any{|e|s.index e}
		puts :normal
		exit
	end
}
