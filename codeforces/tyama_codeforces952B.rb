#!/usr/bin/ruby
10.times{|i|
	p i
	STDOUT.flush
	s=gets.chomp
	if %w(worse terrible serious die even).any?{|e|s.index e}
		puts :grumpy
		exit
	elsif %w(cool great think touch bad).any?{|e|s.index e}
		puts :normal
		exit
	end
}
