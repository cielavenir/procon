#!/usr/bin/ruby
n,k=gets.split.map &:to_i
s=gets.chomp
a=[]
pre=nil
s.each_char.with_index{|c,i|
	if c!=pre
		a<<[c.to_i,i]
	end
	pre=c
}
p a.map.with_index{|(c,j),i|
	t=i+2*k+c
	(t>=a.size ? n : a[t][1]) - j
}.max
