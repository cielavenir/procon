#!/usr/bin/ruby
def conway(a)
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
	b
end

a=[gets.to_i]
(gets.to_i-1).times{
	a=conway(a)
}
puts a*' '
