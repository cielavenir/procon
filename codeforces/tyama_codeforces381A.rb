#!/usr/bin/ruby
gets
a=gets.split.map(&:to_i)
r=[0,0]
f=0
while !a.empty?
	if a.first>a.last
		r[f]+=a.shift
	else
		r[f]+=a.pop
	end
	f^=1
end
puts r*' '