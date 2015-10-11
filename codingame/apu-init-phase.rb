#!/usr/bin/ruby
W=gets.to_i
H=gets.to_i
M=H.times.map{gets.chomp}+['']
H.times{|h|W.times{|w|if M[h][w]=='0'
	puts ( [w,h]+
			((z=(w+1...W).find{|e|M[h][e]=='0'})?[z,h]:[-1,-1])+
			((z=(h+1...H).find{|e|M[e][w]=='0'})?[w,z]:[-1,-1])
		)*' '
end}}