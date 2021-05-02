#!/usr/bin/ruby
n,m=gets.split.map &:to_i
A=n.times.map{gets.split.map &:to_i}
B=m.times.map{gets.split.map &:to_i}
puts A.map{|x,y|
	1+(0...m).min_by{|i|[(B[i][0]-x).abs+(B[i][1]-y).abs,i]}
}
