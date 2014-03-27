#!/usr/bin/ruby
T=gets.to_i
n=gets.to_i
a=gets.split.map(&:to_i)
gets
b=gets.split.map(&:to_i)
#greedy
i=-1
puts b.all?{|e|
	i+=1
	while i<n
		i=n if e-a[i]<0
		break if e-a[i]<=T
		i+=1
	end
	i<n
} ? :yes : :no