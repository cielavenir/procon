#!/usr/bin/ruby
n,l,t=gets.split.map &:to_i
q=0
a=[]
n.times{
	x,y=gets.split.map &:to_i
	x+=t*(y*-2+3)
	q+=x/l # x/l is floor
	a<<x%l
}
puts a.sort.rotate(q%n)
