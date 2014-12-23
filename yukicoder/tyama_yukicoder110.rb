#!/usr/bin/ruby
a=2.times.map{gets;gets.split.map(&:to_i).sort}
p [0,1].map{|e|
	c=a[e][0]
	i=[0,0]
	t=e^r=1
	loop{
		i[t]+=1 until(f=i[t]>=a[t].size)||c<v=a[t][i[t]]
		break if f
		c=v
		r+=1
		t^=1
	}
	r
}.max