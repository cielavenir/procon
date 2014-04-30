#!/usr/bin/ruby
1.step(gets.to_i){|i|
	s=''
	s+='Fizz' if i%3==0
	s+='Buzz' if i%5==0
	puts s.empty? ? i : s
}