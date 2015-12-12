#!/usr/bin/ruby
a,b,c,d,e=$<.read.split.map(&:to_i)
n=[a,b].max
i=0
loop{
	k=0
	k+=c if a<=i
	k+=d if b<=i
	break if e<k
	e-=k
	i+=1
}
p i