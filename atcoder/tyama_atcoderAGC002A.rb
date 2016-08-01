#!/usr/bin/ruby
n,m=gets.split.map(&:to_i)
s=[1]*n
r=[true]+[false]*~-n
m.times{
	x,y=gets.split.map{|e|e.to_i-1}
	r[y]=true if r[x]
	s[x]-=1
	s[y]+=1
	r[x]=false if s[x]==0
}
p r.count{|e|e}