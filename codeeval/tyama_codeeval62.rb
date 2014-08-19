#!/usr/bin/ruby
while gets
	a=$_.split(',').map(&:to_i)
	d=a[0]/a[1]
	p a[0]-a[1]*d
end