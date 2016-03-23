#!/usr/bin/ruby
M=$<.map{|e|e.split.map(&:to_i)}
M.size.times{|h|
	loop{
		f=true
		0.upto(M[h].size-1){|w|
			if M[h][w]>0
				puts '%d %d'%[h+1,w+1]
				M[h][w]-=1
				f=false
				break if M[h][w]!=M[h][w+1].to_i
			end
		}
		break if f
	}
}