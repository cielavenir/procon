#!/usr/bin/ruby
n,*a=$<.read.split.map &:to_i
r=2
h={}
a.sort!
a.each{|e|h[e]=1}
n.times{|i|(i+1...n).each{|j|
	d=a[j]-a[i];r=[r,(2..1/0.0).find{|k|!h[a[i]+d*k]}].max
}}
p r
