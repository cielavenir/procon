#!/usr/bin/ruby
while gets
a=$_.split(',').map(&:to_i)
m=a[0]
(a.size-1).times{|i|
	r=0
	(i..a.size-1).step{|j|
		r+=a[j]
		m=r if m<r
	}
}
p m
end