#!/usr/bin/ruby
h=Hash.new 0
d=r=0
gets.chomp.chars{|c|
	if c=='('
		d+=1
		h[d]+=1
	else
		r+=h[d];h[d+1]=0
		d-=1
		d=0 if d<0
	end
}
p r
