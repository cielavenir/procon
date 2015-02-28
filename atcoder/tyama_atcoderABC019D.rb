#!/usr/bin/ruby
STDOUT.sync=true
N=gets.to_i
a=[0]+(2..N).map{|i|
	puts "? 1 #{i}"
	gets.to_i
}
n=a.each.with_index(1).max[1]
b=(1..N).map{|i|
	puts "? #{n} #{i}"
	gets.to_i
}
puts "! #{b.max}"