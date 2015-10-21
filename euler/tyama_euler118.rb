#!/usr/bin/ruby
require 'prime'
z=0
[*1..9].permutation{|a|
	(1<<8).times{|i|
		x=a[0]
		b=[]
		0.upto(a.size-2){|j|
			if i[j]==1
				b<<x
				x=0
			end
			x=x*10+a[j+1]
		}
		b<<x
		if 0.upto(b.size-2).all?{|i|b[i]<b[i+1]}
			if b.all?(&:prime?)
				p b
				p z+=1
			end
		end
	}
}
p z