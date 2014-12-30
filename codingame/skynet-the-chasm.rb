#!/usr/bin/ruby
STDOUT.sync = true
R = gets.to_i
G = gets.to_i
L = gets.to_i

loop{
	s = gets.to_i
	x = gets.to_i
	if s+x-1>=R
		puts 'JUMP'
		break
	elsif s<=G
		puts 'SPEED'
	elsif s>G+1
		puts 'SLOW'
	else
		puts 'WAIT'
	end
}
loop{puts 'SLOW'}