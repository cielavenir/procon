#!/usr/bin/ruby
n=gets.to_i
a=n.times.map{gets.split.map(&:to_i)[1..-1]}
r=[]
loop{
	f=true
	a.each{|e|e.empty?||(r<<e.shift;f=false)}
	f&&break
}
puts r*' '
