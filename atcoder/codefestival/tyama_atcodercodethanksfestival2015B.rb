#!/usr/bin/ruby
A=gets.split.map(&:to_i)
B=gets.split.map(&:to_i)
n=[gets.to_i]
r=[]
A.product(B){|e|
	r<<((e-n)[0]||n[0]) if (e-n).size<2
}
r=r.sort.uniq
p r.size
puts r