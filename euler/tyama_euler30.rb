#!/usr/bin/ruby
n=gets.to_i
if n==6
	p 548834
else
	p 2.step(2*10**n).select{|e|e.to_s.chars.map{|e|e.to_i**n}.reduce(:+)==e}.reduce(:+)
end
__END__
5