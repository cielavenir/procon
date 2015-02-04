#!/usr/bin/env ruby
R,C=gets.split.map(&:to_i)
R.times{|i|
	if i%4==1
		puts '.'*(C-1)+'#'
	elsif i%4==3
		puts '#'+'.'*(C-1)
	else
		puts '#'*C
	end
}