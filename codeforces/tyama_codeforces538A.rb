#!/usr/bin/env ruby
T='CODEFORCES'
S=gets.chomp
0.step(S.size){|i|
	i.step(S.size){|j|
		if S[0,i]+S[j..-1]==T
			puts :YES
			exit
		end
	}
}
puts :NO