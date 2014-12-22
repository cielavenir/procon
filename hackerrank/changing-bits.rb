#!/usr/bin/ruby
n,q=gets.split.map(&:to_i)
a=gets.to_i(2)
b=gets.to_i(2)
q.times{
	x=gets.split
	if x[0]=='set_a'
		a^=1<<x[1].to_i if a[x[1].to_i]!=x[2].to_i
	elsif x[0]=='set_b'
		b^=1<<x[1].to_i if b[x[1].to_i]!=x[2].to_i
	elsif x[0]=='get_c'
		print (a+b)[x[1].to_i]
	end
}
puts