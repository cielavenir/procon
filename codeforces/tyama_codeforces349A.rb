#!/usr/bin/ruby
h={1=>0,2=>0}
gets;gets.split.each{|a|
	e=a.to_i/25
	if e==1
		h[1]+=1
	elsif e==2
		if h[1]>=1
			h[1]-=1
			h[2]+=1
		else
			puts :NO
			exit
		end
	else
		if h[2]>=1&&h[1]>=1
			h[2]-=1
			h[1]-=1
		elsif h[1]>=3
			h[1]-=3
		else
			puts :NO
			exit
		end
	end
}
puts :YES