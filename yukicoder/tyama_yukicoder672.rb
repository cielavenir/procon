#!/usr/bin/ruby
r=k=0
h={0=>-1}
gets.chomp.each_char.with_index{|c,i|
	if c=='A'
		k+=1
	else
		k-=1
	end
	if h[k]
		r=[r,i-h[k]].max
	else
		h[k]=i
	end
}
p r
