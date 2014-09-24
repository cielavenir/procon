#!/usr/bin/ruby
while(n=gets.to_i)!=-1
	q,r=n.divmod(21)
	if r==20
		puts :NA
	else
		puts q*20+r
	end
end