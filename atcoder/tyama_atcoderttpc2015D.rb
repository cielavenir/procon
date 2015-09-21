#!/usr/bin/ruby
require 'prime'
h=Hash.new{|h,k|h[k]=[]}
s=gets.chomp
s.each_char.with_index{|c,i|h[c]<<i}
if h.size>5
	p -1
else
	key=h.keys.join
	x=%w(1 3 5 7 9).permutation(key.size){|a|
		s0=s.tr(key,a.join).to_i
		break s0 if s0.prime?
	}
	p x.is_a?(Integer) ? x : -1
end