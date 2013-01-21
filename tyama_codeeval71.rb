#!/usr/bin/ruby
while gets
a=$_.chomp.split ';'
b=a[0].split(',').map(&:to_i)
c=a[1].to_i
puts b.each_slice(c).map{|e|
	f=e
	f=e.reverse if e.length==c
	f.join','
}.join','
end