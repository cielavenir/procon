#!/usr/bin/ruby
r=0
a=gets.chomp.split('')
1.step(a.size){|i|
	a.combination(i){|b|
		r=(r+b.join.to_i)%1000000007
	}
}
p r