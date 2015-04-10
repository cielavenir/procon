#!/usr/bin/ruby
h={}
(1..5e6).map{|i|h[i*(i+1)/2]=i}
gets.to_i.times{
	x=h[gets.to_i]
	if x
		puts "Go On Bob "+x.to_s
	else
		puts "Better Luck Next Time"
	end
}