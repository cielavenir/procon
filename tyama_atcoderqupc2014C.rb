#!/usr/bin/ruby
n,m,q=gets.split.map(&:to_i)
h={}
n.times{|i|
	gets.chomp.chars.each_with_index{|c,j|
		if c!='*'
			h[c]=[i+1,j+1]
		end
	}
}
q.times{
	c=gets.chomp
	puts h[c] ? h[c]*' ' : :NA
}