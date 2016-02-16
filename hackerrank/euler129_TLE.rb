#!/usr/bin/ruby
#gets.to_i.times{
#	n=gets.to_i
0.step(10**6){|n|
	if n.gcd(10)!=1
		p 0
		next
	end
	j=1
	k=1
	loop{
		if k==0
			p j
			break
		end
		j+=1
		k=(k*10+1)%n
	}
}