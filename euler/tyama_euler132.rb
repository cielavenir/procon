#!/usr/bin/ruby
require 'prime'

class Integer
	def pow_binary_mod(y,m)
		x = self
		z = 1
		while y != 0
			while y % 2 == 0
				x = x * x % m
				y = y / 2
			end
			y = y - 1
			z = z * x % m
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