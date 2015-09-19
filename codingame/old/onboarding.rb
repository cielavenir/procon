#!/usr/bin/ruby
STDOUT.sync=true
loop{
	name1=gets.chomp
	d1=gets.to_i
	name2=gets.chomp
	d2=gets.to_i
	puts d1<d2 ? name1 : name2
}