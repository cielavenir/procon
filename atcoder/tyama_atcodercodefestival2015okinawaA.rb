#!/usr/bin/ruby
H,W,K=gets.split.map(&:to_i)
h=(H+1)/2
w=(W+1)/2
if h*w<K
	puts :IMPOSSIBLE
else
	a=H.times.map{'.'*W}
	K.times{|k|a[k/w*2][k%w*2]='#'}
	puts a
end