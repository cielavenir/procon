#!/usr/bin/ruby
n,k=gets.split.map(&:to_i)
a=gets.split.map(&:to_i).sort
s=i=0
while s<k
	s+=a[i]
	i+=1
end
p i-1