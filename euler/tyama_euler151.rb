#!/usr/bin/ruby
def r(e,d)
	return 0 if d==16
	s=e.reduce(:+)
	p=s==1?1:0
	5.times{|i|
		next if e[i]==0
		e2=e.dup
		e2[i]-=1
		(i+1).step(4){|j|e2[j]+=1}
		p+=e[i].to_f/s*r(e2,d+1)
	}
	p
end
puts"%.6f"%[r([1,0,0,0,0],0)-2]