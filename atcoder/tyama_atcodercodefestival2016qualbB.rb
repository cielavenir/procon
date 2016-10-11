#!/usr/bin/ruby
n,a,b=gets.split.map(&:to_i)
puts gets.chomp.chars.map{|c|
	if c=='c'
		:No
	elsif c=='b'
		if b>0
			b-=1
			:Yes
		else
			:No
		end
	else
		if a>0
			a-=1
			:Yes
		elsif b>0
			b-=1
			:Yes
		else
			:No
		end
	end
}
