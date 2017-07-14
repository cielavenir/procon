#!/usr/bin/ruby
N=gets.to_i
loop{
	s=%w(1 2 3 4 5 6 8 9).sample(8).join.to_i
	t=N-s
	if !t.to_s.index('7')
		puts '%d %d'%[s,t]
		exit
	end
}
