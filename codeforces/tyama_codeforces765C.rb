#!/usr/bin/ruby
k,a,b=gets.split.map(&:to_i)
if (a%k!=0&&b<k) || (b%k!=0&&a<k)
	p -1
else
	p a/k+b/k
end
