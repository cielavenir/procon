#!/usr/bin/ruby
gets
a=gets.split.map &:to_i
Z={}
r=[]
gets.split.each{|e|
	n=e.to_i
	next if Z[n]
	v=nil
	Z[v=a.shift]=1 while a[0]&&v!=n
	break if v!=n
	r<<n
}
p *r.sort
