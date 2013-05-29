#!/usr/bin/ruby
r={}
1.upto(1/0.0).each{|i|
	x=i**2
	break if x>10**8
	(i+1..1/0.0).each{|j|
		x+=j**2
		break if x>10**8
		s=x.to_s
		r[x]=1 if s==s.reverse
	}
}
p r.keys.reduce(:+)