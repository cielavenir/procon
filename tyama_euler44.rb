#!/usr/bin/ruby
a=1.step(9999).map{|i|i*(3*i-1)/2}
h={}
a.each{|e|h[e]=1}
b=[]
a.length.times{|i|
	(i+1).step(a.length-1){|j|
		if h[a[j]+a[i]] && h[a[j]-a[i]] then b<<a[j]-a[i] end
	}
}
p b.min