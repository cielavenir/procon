#!/usr/bin/ruby
while gets
a=$_.chomp.split ';'
b=a[0].split(',').map(&:to_i)
c=a[1].to_i
ret=[]
b.each_slice(c){|e|
	f=e
	f=e.reverse if e.length==c
	ret<<f.join(',')
}
puts ret.join(',')
end