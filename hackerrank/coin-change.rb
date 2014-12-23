#!/usr/bin/ruby
a=gets.split(', ').map(&:to_i)
n=gets.to_i
bag=[0]*(n+1)
bag[0]=1
a.each{|e|
	(e..n).each{|f|
		bag[f]+=bag[f-e]
	}
}
p bag[n]