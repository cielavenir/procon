#!/usr/bin/ruby
STDOUT.sync=true
A=3.times.map{gets.to_i}
loop{
	a=4.times.map{gets.chomp}
	b=gets.split.map(&:to_i)
	STDERR.puts a.inspect+' '+b.inspect
    
    puts "C"
}