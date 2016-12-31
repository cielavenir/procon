#!/usr/bin/ruby
s=0
gets.to_i.times{
	x,y=gets.split
	if y=='North'
		s-=x.to_i
	elsif y=='South'
		s+=x.to_i
	else
		if s==0||20000==s
			puts :NO
			exit
		end
		next
	end
	if s<0||20000<s
		puts :NO
		exit
	end
}
puts s==0 ? :YES : :NO
