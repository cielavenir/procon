#!/usr/bin/env ruby
n,x=gets.split.map(&:to_i)
cur=1
ret=0
n.times{
	l,r=gets.split.map(&:to_i)
	ret+=r+1-l+(l-cur)%x
	cur=r+1
}
p ret