#!/usr/bin/ruby
require 'prime'

class Integer
	def pow_binary_mod(y,m)
		x = self
		z = 1
		while y!=0
			z=z*x%m if y&1!=0
			x=x*x%m
			y>>=1
		end
		z
	end
end

gets.to_i.times{
a,b,k=gets.split.map(&:to_i)
m=a**b
enum=Prime::EratosthenesGenerator.new;enum.next;enum.next #2,3
p Enumerator.new{|y|
	loop{
		e=enum.next
		y << e if a.pow_binary_mod(a**b,e)==1
	}
}.take(k).reduce(:+)
}
__END__
1
10 9 40
