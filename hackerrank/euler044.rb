#!/usr/bin/ruby
a=1.step(1000000).map{|i|i*(3*i-1)/2}
h={}
a.each{|e|h[e]=1}
N,K=gets.split.map(&:to_i)
K.step(N-1){|i|
	if h[a[i]-a[i-K]] || h[a[i]+a[i-K]] then p a[i] end
}