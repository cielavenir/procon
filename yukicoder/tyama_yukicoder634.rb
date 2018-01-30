#!/usr/bin/ruby
n=gets.to_i
h={}
i=0
loop{
	k=i*-~i/2
	break if k>n
	h[k]=i+=1
}
p h[n]?1:h.keys.any?{|e|h[n-e]}?2:3
