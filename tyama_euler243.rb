#!/usr/bin/ruby
#based on http://freelancersunite.net/project_euler/project-euler-problem-243/
require 'prime'
class Integer
	def totient() self.prime_division.reduce(1){|s,e|s*=(e[0]-1)*e[0]**(e[1]-1)} end
end
g=Prime::EratosthenesGenerator.new
n=g.next*g.next*g.next*g.next*g.next
loop{
	a=g.next
	1.step(a-1){|i|
		d=n*i
		if Rational(d.totient,d-1)<Rational(15499,94744) then p d;exit end
	}
	n*=a
}