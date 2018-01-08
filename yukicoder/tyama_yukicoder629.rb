#!/usr/bin/ruby
(n,m),a,*q=$<.map{|e|e.split.map &:to_i}
h=Hash.new{|h,k|h[k]=[]}
q.each{|u,v|h[u-1]<<v-1;h[v-1]<<u-1}
puts h.any?{|k,v|
	h0=Hash.new 0
	h1=Hash.new 0
	v.each{|e|
		h0[a[e]]+=1 if a[k]<a[e]
		h1[a[e]]+=1 if a[k]>a[e]
	}
	[h0,h1].map{|g|
		x=g.values.reduce(0,:+)
		x=x*~-x/2
		g.each_value{|w|x-=w*~-w/2}
		x
	}.reduce(:+)>0 # 門松パスの個数
} ? :YES : :NO
