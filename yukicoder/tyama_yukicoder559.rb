#!/usr/bin/ruby
i=t=r=0
s=gets.chomp.chars{|c|
	if c=='A'
		r+=i-t
		t+=1
	end
	i+=1
}
p r
