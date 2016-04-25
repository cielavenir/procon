#!/usr/bin/ruby
class Calculator
	def power(n,p)
		if n<0||p<0
			raise 'n and p should be non-negative'
		end
		n**p
	end
end

myCalculator=Calculator.new()
T=gets.to_i
for i in 1..T
	n,p = gets.split.map(&:to_i)
	begin
		ans=myCalculator.power(n,p)
		puts ans
	rescue Exception=> e
		puts e
	end
end