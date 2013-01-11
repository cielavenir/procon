#!/usr/bin/ruby
def fizzbuzz(n)
	if n%3==0&&n%5==0 then return 'FizzBuzz' end
	if n%3==0 then return 'Fizz' end
	if n%5==0 then return 'Buzz' end
	return n.to_s
end
while(m,n=gets.split.map(&:to_i))!=[0,0]
	a=[*1..m]
	c=0
	1.step(n){|i|
		s=gets.chomp
		if a.length>1
			if s!=fizzbuzz(i) then a.delete_at(c);c%=a.length else c=(c+1)%a.length end
		end
	}
	puts a*' '
end