#!/usr/bin/ruby
h,w=gets.split.map(&:to_i)
n=gets.to_i
r=c=0
n.times.map{gets.split}.reverse.each{|(s,k)|
	r=(r+h-1)%h if s=="C"&&k.to_i==c
	c=(c+w-1)%w if s=="R"&&k.to_i==r
}
puts ["white","black"][(r+c)%2]