#!/usr/bin/ruby
n,m=gets.split.map(&:to_i)
h=Hash.new{|h,k|h[k]=[]}
n.times{
	a,b,c=gets.split
	h[b.to_i-1]<<[-c.to_i,a]
}
m.times{|i|
	h[i].sort!
	if h[i].size<=2 || h[i][1][0]!=h[i][2][0]
		puts h[i][0,2].map(&:last)*' '
	else
		puts '?'
	end
}