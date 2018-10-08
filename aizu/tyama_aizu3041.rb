#!/usr/bin/ruby
n,q=gets.split.map &:to_i
idx=0
q.times{
	a,b=gets.split.map &:to_i
	a==0 ? p((idx+b-1)%n+1) : idx=(idx+b)%n
}
