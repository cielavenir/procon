#!/usr/bin/ruby
h=Hash.new(0)
gets.chomp.each_char{|c|h[c]+=1}
g=Hash.new(0)
gets.chomp.each_char{|c|g[c]+=1}
r=0
g.each{|k,v|
	if h[k]==0
		p -1
		exit
	end
	r+=[h[k],v].min
}
p r