#!/usr/bin/ruby
X=gets.to_i;gets;r=[l=m=k=0,0,*gets.split.map(&:to_i)];gets;h=X
p *$<.map{|e|
	t,a=e.split.map &:to_i
	(l=[X,[l+z=(-1)**k*(r[k+1]-r[k]),0].max].min;h=[X,[h+z,0].max].min;m+=z;k+=1)while k<r.size-1&&t>=r[k+1]
	[X,[(-1)**k*(t-r[k])+[h,[l,a+m].max].min,0].max].min
}
