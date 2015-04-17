#!/usr/bin/env ruby
a=[]
1.step(9){|i|
	[4,7].repeated_permutation(i){|e|a<<e.join.to_i}
}
a.sort!
p a.index(gets.to_i)+1