#!/usr/bin/ruby
x=y=u=0
gets.chars{|c|
	x-=1 if c=='L'
	x+=1 if c=='R'
	y-=1 if c=='U'
	y+=1 if c=='D'
	u+=1 if c=='?'
}
x=x.abs+y.abs
p gets.to_i==1 ? x+u : x>u ? x-u : (x-u)%2