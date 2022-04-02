#!/usr/bin/ruby
def solveC(a)
	r=0
	a.sort.each{|e|
		if e>r
			r+=1
		end
	}
	r
end
t=gets.to_i
t.times{|i|
	print "Case #%d: "%(i+1)
	gets
	a=gets.split.map(&:to_i)
	puts solveC(a)
}
