#!/usr/bin/ruby
a=[gets.to_i]
(gets.to_i-1).times{
	b=[]
	count=1
	cur=a[0]
	1.step(a.size-1){|i|
		if a[i]!=cur
			b<<count
			b<<cur
			count=1
			cur=a[i]
		else
			count+=1
		end
	}
	b<<count
	b<<cur
	a=b
}
puts a*' '