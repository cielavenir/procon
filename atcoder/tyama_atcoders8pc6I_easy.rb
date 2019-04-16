#!/usr/bin/ruby
H,W=gets.split.map &:to_i
H.times{|h|
	if h%4==1
		puts '#'+'.'*(W-1)
	elsif h%4==3
		puts '.'*(W-1)+'#'
	else
		puts '#'*W
	end
}
