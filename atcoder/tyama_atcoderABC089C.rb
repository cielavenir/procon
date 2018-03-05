#!/usr/bin/ruby
T={?M=>0,?A=>1,?R=>2,?C=>3,?H=>4}
a=[0]*5
gets.to_i.times{
	c=gets[0]
	T[c]&&a[T[c]]+=1
}
p a.combination(3).map{|x,y,z|x*y*z}.reduce(:+)
