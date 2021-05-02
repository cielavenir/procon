#!/usr/bin/ruby
a=$<.map{|e|e.chomp.chars}
c=0
loop{
	if a[c].empty?
		putc 65+c
		exit
	end
	c=a[c].shift.ord-97
}