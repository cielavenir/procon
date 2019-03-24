#!/usr/bin/ruby
n,m,c=gets.split.map &:to_i
f=[-1]*n
x=r=0
a=gets.split.map &:to_i
gets.split.map{|e|e.to_i-1}.each{|e|
	f[e]=-f[e]
	x+=f[e]*a[e]
	r=[x,r].max
}
puts r>c ? "Fuse was blown." : "Fuse was not blown.\nMaximal consumed current was %d A."%r
