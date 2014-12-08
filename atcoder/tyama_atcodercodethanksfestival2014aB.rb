#!/usr/bin/ruby
n=gets.to_i
a=$<.map{|e|e.to_i}.sort.reverse
s=0
i=0
while s<n
	s+=a[i%3]
	i+=1
end
p i