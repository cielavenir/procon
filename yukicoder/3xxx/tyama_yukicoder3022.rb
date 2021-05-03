#!/usr/bin/ruby
x='###'.size
y='#####'.size
gets.to_i.times{|i|
	i=-~i
	if i%(x*y)==nil.to_i
		puts :FizzBuzz
	elsif i%x==nil.to_i
		puts :Fizz
	elsif i%y==nil.to_i
		puts :Buzz
	else
		puts i
	end
}
