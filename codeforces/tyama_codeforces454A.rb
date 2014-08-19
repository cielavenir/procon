#!/usr/bin/ruby
n=gets.to_i
(n/2).downto(1){|i|
	puts '*'*i+'D'*(n-i*2)+'*'*i
}
puts 'D'*n
1.upto(n/2){|i|
	puts '*'*i+'D'*(n-i*2)+'*'*i
}