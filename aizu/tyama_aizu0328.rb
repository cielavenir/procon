#!/usr/bin/ruby
#We need bignum...
n=0
gets.to_i.times{
	a,b=gets.split.map &:to_i
	n+=1<<(a+b)
}
n.to_s(2).reverse.chars.each_with_index{|c,i|
	puts '%d 0'%i if c=='1'
}
