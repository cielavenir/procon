#!/usr/bin/ruby
h=Hash.new(0)
r=0
gets
gets.split.map(&:to_i).each{|e|h[e]+=1}
h.each{|k,v|
	x=2
	while x<=0x80000000
		y=x-k
		if k==y
			r+=v*(v-1)/2
		elsif k<y
			r+=v*h[y]
		end
		x*=2
	end
}
p r