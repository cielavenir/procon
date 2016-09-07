#!/usr/bin/ruby
n=gets.to_i
if n==1
	p 0
else
	h=Hash.new(0)
	(2...n).each{|q|
		(2..1/0.0).each{|r|
			x=(q**r-1)/(q-1)
			break if x>n
			h[x]+=1
		}
	}
	r=1
	(1...n).each{|e|
		if n%e==0
			r+=h[n/e]
			r+=1 if e!=1
		end
	}
	p r
end