#!/usr/bin/ruby
gets.to_i.times{
	a,b=gets.split.map &:to_i
	t=a*b
	s=Math.sqrt(t).to_i
	r=2*s-2
	r-=1 if s*s==t
	r+=1 if s*(s+1)<t
	r+=1 if a==b
	p r
}
