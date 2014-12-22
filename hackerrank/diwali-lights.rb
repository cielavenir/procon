#!/usr/bin/ruby
gets.to_i.times{
	p ((1<<gets.to_i)-1)%100000
}