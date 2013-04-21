#!/usr/bin/ruby
while s=gets
	a=s.chomp.split.reverse
	i=1
	loop{
		if a[0,i]*2==a[0,i*2] then puts a[0,i].reverse*' ';break end
		i+=1
		if i>a.size/2 then puts a.reverse*' ';break end #cycle is 1, bad input...
	}
end