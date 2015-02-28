#!/usr/bin/env ruby
def f(a,b)
	a[b.size.times.find{|i|
		a[i]<b[i]
	}||b.size]
end
x=$<.drop(1).map{|e|e.split.map(&:to_i).sort}
p f(x[0],x[1]),f(x[1],x[2])