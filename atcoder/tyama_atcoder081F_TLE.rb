#!/usr/bin/ruby
H,W=gets.split.map &:to_i
M=$<.to_a
a=[1]*(W-1)+[0]
r=[H,W].max
b=(0...W-1).map{|w|M[0][w,2].count('#')}
(H-1).times{|h|
	(W-1).times{|w|
		a[w]=(b[w]+b[w]=M[h+1][w,2].count('#'))%2<1?a[w]+1:1
	}
	t=[-1]
	W.times{|w|
		r=[r,a[t.pop]*(w-t[-1])].max while t.size>1&&a[t[-1]]>=a[w]
		t<<w
	}
}
p r
