#!/usr/bin/ruby
n,*a=4.times.map{gets.to_i}
if a.include?(n)
	puts :NO
	exit
end
100.times{|i|
	if n>=3 && !a.include?(n-3)
		n-=3
	elsif n>=2 && !a.include?(n-2)
		n-=2
	elsif n>=1 && !a.include?(n-1)
		n-=1
	end
	if n==0
		puts :YES
		exit
	end
}
puts :NO