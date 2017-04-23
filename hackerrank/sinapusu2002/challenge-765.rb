#!/usr/bin/ruby
a=gets.to_i.times.map{
	x,y=gets.split.map(&:to_i)
	y-x
}.sort
b=gets.to_i.times.map{gets.to_i}.sort
p a.count{|e|
	if e<0
		true
	else
		idx=(0...b.size).bsearch{|i|b[i]>e}
		if idx
			b.delete_at(idx)
			true
		else
			false
		end
	end
}
