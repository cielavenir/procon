#!/usr/bin/ruby
a,b=gets.split.map(&:to_i).sort
g=a.gcd b
a/=g
b/=g
if [a,b]==[1,1]||[a,b]==[2,3]
	p g
elsif [a,b]==[1,2]
	p 3*g
elsif [a,b]==[1,3]
	p 2*g
else
	p -1
end
