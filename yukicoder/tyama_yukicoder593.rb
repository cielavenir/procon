#!/usr/bin/ruby
n=(s=gets).to_i(4)
if n%15==0
	puts :FizzBuzz
elsif n%3==0
	puts :Fizz
elsif n%5==0
	puts :Buzz
else
	puts s
end
