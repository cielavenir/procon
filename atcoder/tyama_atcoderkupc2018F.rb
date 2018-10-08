#!/usr/bin/ruby
n,m=gets.split.map &:to_i
s=gets.split.map(&:to_i).map{|e|2*e}
m.times{
	a,b,c=gets.split.map &:to_i
	s[a-1]+=c
	s[b-1]+=c
}
a=s.sort_by(&:-@).each_slice(2).to_a
x,y=a.shift.zip(*a).map{|e|e.map(&:to_i).reduce(:+)}
puts x>y ? :First : :Second
