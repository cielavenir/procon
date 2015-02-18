#!/usr/bin/ruby
puts$<.drop(1).map{|e|
	w=g=r=f=0
	e.chomp.bytes{|c|
		if c==82
			r+=1
			break if g<r
		elsif c==71
			f=0
			g+=1
			break if w<g
		else
			w+=f=1
		end
	}&&g==r&&f==0?:possible: :impossible
}