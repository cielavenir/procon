#!/usr/bin/env ruby
#https://mtsmfm.github.io/2017/11/04/doukaku-e19.html
#http://qiita.com/mtsmfm/items/67bf5c121ecbd9b5fab3

#o -> odd, x->even

def enum(a,d,s,n)
	return if s>=n
	if a[d]==a[d+1]
		#if s
		s+1
	else
		s=s/2*2
	end
end


while gets
	x,y=$_.chomp.split(',')
	enum(x,x.size){}
	STDOUT.flush
end
