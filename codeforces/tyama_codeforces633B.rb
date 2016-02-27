#!/usr/bin/ruby
N=gets.to_i
A=Enumerator.new{|y|
	s=0
	(1..1/0.0).each{|n|
		i=n
		r=0
		while i%5==0
			r+=1
			i/=5
		end
		s+=r
		y<<[s,n]
	}
}.lazy.drop_while{|e,n|e<N}.take_while{|e,n|e==N}.map(&:last).to_a
p A.size
puts A*' '