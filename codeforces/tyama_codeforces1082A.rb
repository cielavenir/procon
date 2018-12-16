#!/usr/bin/ruby
gets.to_i.times{
	n,x,y,d=gets.split.map &:to_i
	r = Float::INFINITY
	(y-1)%d==0 && r=[r,(x+d-2)/d+(y-1)/d].min
	(n-y)%d==0 && r=[r,(n+d-x-1)/d+(n-y)/d].min
	(y-x)%d==0 && r=[r,(y-x).abs/d].min
	p r.is_a?(Integer) ? r : -1
}
