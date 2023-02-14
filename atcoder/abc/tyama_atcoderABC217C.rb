#!/usr/bin/ruby
def reverseperm(a)
	r=[nil]*a.size
	a.size.times{|i|
		r[a[i]-1]=i+1
	}
	r
end
gets;puts reverseperm(gets.split.map(&:to_i))*' '
