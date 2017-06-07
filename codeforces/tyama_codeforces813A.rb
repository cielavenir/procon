#!/usr/bin/ruby
gets
s=gets.split.map(&:to_i).reduce(:+)
gets.to_i.times{
	l,r=gets.split.map(&:to_i)
	s<=r&&(p [l,s].max;exit)
}
p -1
