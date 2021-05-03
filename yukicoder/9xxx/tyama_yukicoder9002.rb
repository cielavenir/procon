#!/usr/bin/ruby
puts (1..gets.to_i).map{|i|
	if i%15==0
		:FizzBuzz
	elsif i%3==0
		:Fizz
	elsif i%5==0
		:Buzz
	else
		i
	end
}