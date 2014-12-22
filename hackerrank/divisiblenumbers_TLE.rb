#!/usr/bin/ruby
n=gets.to_i
(1..1/0.0).each{|i|
	x=(n*i).to_s.split('').map(&:to_i)
	next if x.include?(0)||x.reduce(:+)<x.reduce(:*)
	p x.size
	exit
}