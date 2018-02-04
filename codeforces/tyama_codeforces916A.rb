#!/usr/bin/ruby
x,h,m=$<.read.split.map &:to_i
i=0
m+=h*60
while !("#{m/60}#{m%60}"=~/7/)
	m-=x
	i+=1
end
p i
