#!/usr/bin/ruby
n,a,b=gets.split.map(&:to_i)
j=0.upto(n/a).find{|i|(n-i*a)%b==0}
if !j
	p -1
else
	k=(n-j*a)/b
	s=gets.chomp.chars.to_a
	p j+k
	j.times{puts s.shift(a)*''}
	k.times{puts s.shift(b)*''}
end