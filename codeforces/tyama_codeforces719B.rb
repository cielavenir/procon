#!/usr/bin/ruby
gets
s=[0]*4
x=0
gets.chomp.chars{|c|
	f=c!='r' ? 2 : 0
	s[f|x]+=1
	x^=1
}
p [[s[0],s[3]].max,[s[1],s[2]].max].min
