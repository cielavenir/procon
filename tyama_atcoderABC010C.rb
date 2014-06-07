#!/usr/bin/ruby
require 'complex'
a=gets.split.map(&:to_f)
d=a[4]*a[5]
p=Complex(a[0],a[1])
q=Complex(a[2],a[3])
puts gets.to_i.times.any?{
	r=Complex(*gets.split.map(&:to_f))
	(p-r).abs+(q-r).abs<=d
} ? :YES : :NO