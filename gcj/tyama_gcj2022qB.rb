#!/usr/bin/ruby
N=1000000
def solveB(a)
	n=N
	r=[]
	a.transpose.each{|e|
		v=[n,e.min].min
		n-=v
		r<<v
	}
	n>0 ? :IMPOSSIBLE : r*' '
end
t=gets.to_i
t.times{|i|
	print "Case #%d: "%(i+1)
	a=3.times.map{gets.split.map(&:to_i)}
	puts solveB(a)
}
