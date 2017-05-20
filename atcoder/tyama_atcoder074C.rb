#!/usr/bin/ruby
H,W=gets.split.map &:to_i;p [[H,W],[W,H]].map{|h,w|
	(1..h/2).map{|i|
		x,y=[w*i,w/2*(h-i),(w-w/2)*(h-i)].minmax;z,q=[i,(h-i)/2,h-i-(h-i)/2].minmax;[y-x,(q-z)*w].min
	}.min
}.min
