#!/usr/bin/ruby
a=Hash[%W(G C P).zip gets.split.map(&:to_i)]
b=Hash[gets.chars.group_by{|e|e}.map{|k,v|[k,v.size]}]
b.default=s=0
s=0
[[?G,?C,3],[?C,?P,3],[?P,?G,3],[?G,?G,1],[?C,?C,1],[?P,?P,1]].each{|x,y,m|
	n=[a[x],b[y]].min
	s+=n*m
	a[x]-=n;b[y]-=n
}
p s