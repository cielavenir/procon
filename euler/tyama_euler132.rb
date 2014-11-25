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

M=10**9
enum=Prime::EratosthenesGenerator.new;enum.next;enum.next #2,3
p Enumerator.new{|y|
	loop{
		a=enum.next
		y << a if 10.pow_binary_mod(10**9,a)==1
	}
}.take(40).reduce(:+)