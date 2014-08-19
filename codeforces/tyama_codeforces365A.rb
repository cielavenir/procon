#!/usr/bin/ruby
n,k=gets.split.map(&:to_i)
p n.times.count{
	a=gets.chomp.split('').map(&:to_i)
	(0..k).all?{|e|a.include?(e)}
}