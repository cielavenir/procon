#!/usr/bin/ruby
STDOUT.sync=true
loop{
	puts gets.to_i.times.map{
		enemy,dist=gets.split
		[enemy,dist.to_f]
	}.min_by{|e,d|
		d
	}.first
}