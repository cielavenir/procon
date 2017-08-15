#!/usr/bin/ruby
a=[0,1]
s=[0,1]
(2..gets.to_i).each{|i|
	a<<(s[i%2^1]*i)%(10**9+7)
	s[i%2]+=a[-1]
}
p a[-1]
