#!/usr/bin/ruby
require 'prime'
P=Prime.each(2155).map{|x|x**3}
h=Hash.new(0)
gets
$<.each{|_|
	n=_.to_i
	P.each{|x|break if n<x;n/=x while n%x==0}
	h[n]+=1
}
visit={}
r=[1,h[1]].min
visit[1]=1
h.sort.each{|k,v|
	next if visit[k]
	n=k*k
	P.each{|x|break if n<x;n/=x if n%x==0}
	v=h[n] if v<h[n]
	r+=v
	visit[n]=1
}
p r