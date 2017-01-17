#!/usr/bin/ruby
#Use with 00forker.c
N=200
R=100000
X,Y=900000,900000
N.times{|i|
	s=gets
	if !s
		STDERR.puts i
		exit
	end
	STDERR.puts s
	x,y=s.split.map(&:to_f)
	if x==X && y==Y
		STDERR.puts 'found'
		puts 'found'
	elsif Math.hypot(x-X,y-Y)<=R
		STDERR.puts 'close'
		puts 'close'
	else
		STDERR.puts 'far'
		puts 'far'
	end
	STDOUT.flush
}
STDERR.puts 'kill'
puts 'kill'
