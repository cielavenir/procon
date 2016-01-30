#!/usr/bin/ruby
combination = lambda{|n|
	lambda{|r|
		k=1
		r.times{|i|k=k*(n-i)/(i+1)}
		k
	}
}

n = gets.to_i
r = gets.to_i
nCr = combination.(n)
puts nCr.(r)