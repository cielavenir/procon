#!/usr/bin/ruby
n=gets.to_i
a=gets.chomp
x=(0...n).select{|i|a[i]==?!}
p (0...n).max_by{|i|
	next 0 if a[i]==?!
	x.map{|e|(e-i).abs}.min
}