#!/usr/bin/ruby
gets.to_i.times{
	n=gets.to_i
	puts '%d is %s'%[n,['even','odd'][n%2]]
}