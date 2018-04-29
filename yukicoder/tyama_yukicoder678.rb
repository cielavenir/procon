#!/usr/bin/ruby
n,l,r=gets.split.map &:to_i
z=[0]*n
a=n.times.map{gets.split.map &:to_i}
(l..r).each{|w|
	x=[-1,nil]
	a.each_with_index{|e,i|
		if e[0]<=w&&w<=e[2]
			x=[x,[e[3],i]].max
		end
	}
	z[x[1]]=1 if x[1]
}
p *z
