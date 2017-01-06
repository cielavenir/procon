#!/usr/bin/ruby
x1,v1,x2,v2=gets.split.map(&:to_i)
if v1==v2
	puts x1==x2 ? :YES : :NO
elsif (x1-x2).abs%(v1-v2).abs!=0 || (x1-x2)*(v1-v2)>0
	puts :NO
else
	puts :YES
end
