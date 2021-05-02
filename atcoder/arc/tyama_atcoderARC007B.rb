#!/usr/bin/ruby
n,m=gets.split.map(&:to_i)
h={}
a=(n+1).times.map{|i|h[i]=i}
m.times{
	d=gets.to_i
	a[h[d]],a[0]=a[0],a[h[d]]
	h[a[h[d]]],h[a[0]]=h[a[0]],h[a[h[d]]]
}
1.step(n){|i|p a[i]}