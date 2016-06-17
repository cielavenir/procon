#!/usr/bin/ruby
n=gets.to_i
0.step(n,1234567){|a|
	0.step(n-a,123456){|b|
		if (n-a-b)%1234==0
			puts :YES
			exit
		end
	}
}
puts :NO