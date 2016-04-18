#!/usr/bin/ruby
n=gets.to_i
s=gets.chomp
r=0
n.times{|i|
	x=y=0
	i.upto(n-1){|j|
		x+=1 if s[j]=='L'
		x-=1 if s[j]=='R'
		y+=1 if s[j]=='U'
		y-=1 if s[j]=='D'
		r+=1 if x*x+y*y==0
	}
}
p r