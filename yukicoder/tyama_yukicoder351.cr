#!/usr/bin/env crystal
h,w=gets.not_nil!.split.map(&.to_i)
n=gets.not_nil!.to_i
r=c=0
n.times.map{gets.not_nil!.split}.to_a.reverse.each{|z|
	s,k=z
	r=(r+h-1)%h if s=="C"&&k.to_i==c
	c=(c+w-1)%w if s=="R"&&k.to_i==r
}
puts ["white","black"][(r+c)%2]