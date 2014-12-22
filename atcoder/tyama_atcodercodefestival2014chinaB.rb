#!/usr/bin/ruby
# min n such that 2*n*(n+1) >= v <=> 2*n2+2*n-v>=0 : (-1+sqrt(1+2*v))/2
gets.to_i.times{
	v=gets.to_i
	if v==1
		puts '0 0'
	else
		v-=2
		n=( (-1+Math.sqrt(1+2*v))/2 ).to_i
		v-=2*n*(n+1)
		n+=1
		v+=1
		x=v/2-n
		y=n-x.abs
		y*=-1 if v%2==0
		puts x.to_s+' '+y.to_s
	end
}