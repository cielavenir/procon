#!/usr/bin/ruby
H,W=gets.split.map &:to_i
m=$<.map &:chomp
H.times{|h|W.times{|w|
	if m[h][w]!='#'
		r=0
		(-1..1).each{|dh|(-1..1).each{|dw|
			r+=1 if 0<=h+dh&&h+dh<H && 0<=w+dw&&w+dw<W &&m[h+dh][w+dw]=='#'
		}}
		m[h][w]=r.to_s
	end
}}
puts m
