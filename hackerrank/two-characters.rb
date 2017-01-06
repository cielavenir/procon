#!/usr/bin/ruby
gets
s=gets.chomp
r=0
[*'a'..'z'].combination(2){|a|
	t=s.tr('^'+a*'','')
	next if t=~/(.)\1/ || t.size==1
	r=[r,t.size].max
}
p r
