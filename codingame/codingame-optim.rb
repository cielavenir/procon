#!/usr/bin/ruby
STDOUT.sync=true
A=3.times.map{gets.to_i}
STDERR.puts A.inspect
loop{
	a=4.times.map{gets.chomp}
	b=5.times.map{gets.split.map(&:to_i)}
	STDERR.puts a.inspect+' '+b.inspect
    
    #puts a.count{|e|e=='#'}>1 ? "C" : "C"
    puts a[0]=='#' ? "A" : "C"
}