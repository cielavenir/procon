#!/usr/bin/ruby
s=[0]+gets.chomp.split('').each_cons(2).map{|a,b|a==b ? 1 : 0}
1.step(s.size-1){|i|s[i]+=s[i-1]}
gets.to_i.times{
	a,b=gets.split.map(&:to_i)
	p s[b-1]-s[a-1]
}