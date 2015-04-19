#!/usr/bin/ruby
while(a,b=gets.split.map(&:to_i))!=[0,0]
	r=99999999
	1.step(Math.sqrt(a).to_i){|i|
		if a%i>0 then next end
		1.step(Math.sqrt(b).to_i){|j|
			if b%j>0 then next end
			x=[i,a/i,j,b/j].sort
			p=(x[3]-x[2])**2+(x[2]-x[1])**2+(x[1]-x[0])**2
			if r>p then r=p end
		}
	}
	p r
end