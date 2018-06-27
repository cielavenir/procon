#!/usr/bin/ruby
n,*a=$<.read.split.map &:to_i
a=a.map{|e|e*2}.sort
i=0;s=a.reduce(:+)
while s<n*9
	s+=10-a[i]
	i+=1
end
p i
