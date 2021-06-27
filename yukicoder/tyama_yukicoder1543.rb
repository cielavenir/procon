#!/usr/bin/ruby
a,b,c=gets.split
puts a.to_i.send(c.sub('=','=='),b.to_i) ? :YES : :NO
