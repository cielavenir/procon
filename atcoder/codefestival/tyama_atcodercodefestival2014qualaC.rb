#!/usr/bin/ruby
def leap(n)
	return true if n%400==0
	return false if n%100==0
	return true if n%4==0
	return false
end
a,b=gets.split.map(&:to_i)
if b-a<400
	puts (a..b).count{|e|leap(e)}
else
	r=0
	while a%400!=0
		r+=1 if leap(a)
		a+=1
	end
	while b%400!=0
		r+=1 if leap(b)
		b-=1
	end
	puts r+(b-a)/400*97+1
end