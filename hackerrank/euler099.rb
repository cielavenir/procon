#!/usr/bin/ruby
z=[]
gets.to_i.times{
	a,b=gets.split.map &:to_i
	z<<[b*Math.log(a),a,b]
}
puts z.sort[gets.to_i-1][1,2]*' '