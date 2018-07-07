#!/usr/bin/ruby
h,w=gets.split.map &:to_i
m=$<.map{|e|e.chomp}
r=Float::INFINITY
(-1..h).each{|y|(-1..w).each{|x|
	next if 0<=y&&y<h && 0<=x&&x<w
	r0=0
	(0...h).each{|i|(0...w).each{|j|
		r0+=Math.hypot(y-i,x-j) if m[i][j]==?1
	}}
	r=[r,r0].min
}}
p r
