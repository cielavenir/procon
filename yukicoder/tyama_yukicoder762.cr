#!/usr/bin/env crystal
n,m=gets.not_nil!.split.map &.to_i
s=gets.not_nil!.chomp
a=m.times.map{Tuple(Int32,Int32).from(gets.not_nil!.split.map{|f|f.to_i-1})}.to_a
d=[0]*n
r=0
a.each{|x,y|
	d[y]+=1 if s[x]=='P'&&s[y]=='D'
	d[x]+=1 if s[y]=='P'&&s[x]=='D'
}
a.each{|x,y|
	d[y]+=d[x] if s[x]=='D'&&s[y]=='C'
	d[x]+=d[y] if s[y]=='D'&&s[x]=='C'
}
a.each{|x,y|
	r+=d[x] if s[x]=='C'&&s[y]=='A'
	r+=d[y] if s[y]=='C'&&s[x]=='A'
}
p r%(10**9+7)
