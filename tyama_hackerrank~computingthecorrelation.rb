#!/usr/bin/ruby
def calc(a,b)
	a.zip(b).map{|e|e.reduce(:*)}.reduce(:+) / Math.sqrt(a.map{|e|e**2}.reduce(:+)) / Math.sqrt(b.map{|e|e**2}.reduce(:+))
end
a=gets.to_i.times.map{gets.split.map(&:to_f)}.transpose
ave=a.map{|e|e.reduce(:+)/e.size}
vec=a.zip(ave).map{|e,a|e.map{|f|f-a}}
puts '%.2f'%calc(vec[0],vec[1])
puts '%.2f'%calc(vec[1],vec[2])
puts '%.2f'%calc(vec[2],vec[0])