#!/usr/bin/ruby
def perform(h,w,m,a,b)
	a=h.times.map{[a]*w}
	h.times{|h0|w.times{|w0|
		a[h0][w0]=b if (-1..1).any?{|x|(-1..1).any?{|y|
			0<=h0+y&&h0+y<h && 0<=w0+x&&w0+x<w && m[h0+y][w0+x]==b
		}}
	}}
	a
end
h,w=gets.split.map(&:to_i)
m=h.times.map{gets.chomp.chars.to_a}
k=perform(h,w,m,'#','.')
if perform(h,w,k,'.','#')==m
	puts :possible
	puts k.map(&:join)
else
	puts :impossible
end