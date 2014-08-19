#!/usr/bin/ruby
s=gets.chomp.split('')
r=''
if s.map(&:to_i).reduce(:+)%3==0
	r+='Fizz'
end
if s.last=='0'||s.last=='5'
	r+='Buzz'
end
if r.empty?
	r=s*''
end
puts r