#!/usr/bin/ruby
def solveA(h,w)
	r=[]
	(h+1).times{|n|
		r << ['+']*(w+1)*'-'
		r << ['|']*(w+1)*'.' if n<h
	}
	r[0][0]=r[1][0]=r[0][1]='.'
	r
end
t=gets.to_i
t.times{|i|
	print "Case #%d: \n"%(i+1)
	h,w=gets.split.map(&:to_i)
	puts solveA(h,w)
}
