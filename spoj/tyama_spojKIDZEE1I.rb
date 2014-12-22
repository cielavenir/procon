#!/usr/bin/ruby
gets.to_i.times{|t|
	a,b,c=gets.split.map(&:to_i)
	puts "Case #{t+1}:"
	0.step(a){|i|
		(i+1).step(b){|j|
			(j+1).step(c){|k|
				puts [i,j,k]*' '
			}
		}
	}
}