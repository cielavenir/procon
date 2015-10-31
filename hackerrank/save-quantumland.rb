#!/usr/bin/ruby
gets.to_i.times{
	n=gets.to_i
	a=gets.split.map(&:to_i)
	r=c=0
	a.size.times{|i|
		if a[i]==1
			c=0
		else
			c+=1
			if c==2
				r+=1
				c=0
			end
		end
	}
	p r
}