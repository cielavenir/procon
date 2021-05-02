#!/usr/bin/env crystal
y,x=gets.not_nil!.split.map &.to_i32
m=ARGF.gets_to_end.split
a=[1]*(x-1)+[0]
r=[y,x].max
b=(0...x-1).map{|w|m[0][w,2].count('#')}
(y-1).times{|h|
	(x-1).times{|w|
		c=m[h+1][w,2].count('#')
		a[w]=(b[w]+c)%2<1?a[w]+1:1
		b[w]=c
	}
	t=[-1]
	x.times{|w|
		while t.size>1&&a[t[-1]]>=a[w]
			r=[r,a[t.pop]*(w-t[-1])].max
		end
		t<<w
	}
}
p r
